#include<bits/stdc++.h>
using namespace std;

#define N 220
const long long INF = 1ll << 61;
typedef long long matrix[N][N];

matrix d, tmp, res;
long long L;
char s[N];
int n, m, arr[N];

void init(matrix &a){
	for(int i = 0; i < N; i ++) for(int j = 0; j < N; j ++) a[i][j] = i == j ? 0 : -INF;
}

void multiply(matrix &a, matrix &b){
	init(tmp);
	for(int i = 0; i < m; i ++) for(int j = 0; j < m; j ++)
		for(int k = 0; k < m; k ++) tmp[i][j] = max(tmp[i][j], a[i][k] + b[k][j]);
	for(int i = 0; i < m; i ++) for(int j = 0; j < m; j ++) a[i][j] = tmp[i][j];
}

void pow_m(long long k){
	init(res);
	for(; k ; k >>= 1){
		if(k & 1) multiply(res, d);
		multiply(d, d);
	}
}

class Aho_Crasick{
public:
	struct node{
		int nxt[26], link;
		long long val;
	}tp[N];

	int size;

	int new_node(){
		tp[size].val = tp[size].link = 0;
		memset(tp[size].nxt, 0, sizeof tp[size].nxt);
		return size ++;
	}

	void init(){
		size = 0;
		new_node();
	}

	#define v tp[u].nxt[c]
	#define f tp[tp[u].link].nxt[c]
	#define idx(x) x - 'a'

	void insert(char *s, int _val){
		int u = 0, len = strlen(s);
		for(int i = 0; i < len; i ++){
			int c = idx(s[i]);
			if(!v) v = new_node();
			u = v;
		}
		tp[u].val += _val;
	}

	void build_Aho(){
		int u = 0;
		queue <int> Q;
		for(int c = 0; c < 26; c ++) if(v) {
			Q.push(v);
			d[0][v] = tp[v].val;
		}
		while(!Q.empty()){
			u = Q.front(), Q.pop();
			for(int c = 0; c < 26; c ++){
				if(v){
					Q.push(v);
					tp[v].link = f;
					tp[v].val += tp[f].val;
				}
				else v = f;
				d[u][v] = tp[v].val;
			}
		}
	}
	#undef v
	#undef f
}ACT;

int main(){
	//freopen("d.in", "r", stdin);
	init(d);
	scanf("%d %I64d", &n, &L);
	for(int i = 1; i <= n; i ++) scanf("%d", arr + i);
	ACT.init();
	for(int i = 1; i <= n; i ++){
		scanf("%s", s);
		ACT.insert(s, arr[i]);
	}
	ACT.build_Aho();
	m = ACT.size;
	pow_m(L);
	printf("%I64d\n", *max_element(res[0] + 0, res[0] + m));
}