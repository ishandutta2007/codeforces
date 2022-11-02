#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <queue>
#include <cassert>

using namespace std;

//#define HOME
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define next _next
#define rank _rank
#define prev _prev
#define sz(s) int((s).size())

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;

const double eps = 1e-9;
const double pi = acos(double(-1));
const int inf = int(1e9);
const int maxlen = int(1e5);
const ll hx = ll(2e5 + 3);

struct ts{
	int a, b;
};

struct tr{
	int ls, rs, val, add;
};

int sz;
char buf[100100];
int len[100100], last[100100], cv[100100];
char *s[100100];
ll *h[100100];
ll p[100100], ans[100100];
ts suff[100100];
tr rmq[16000000];

inline ll geth(ll *h, int l, int r){
	return h[r] - (l > 0 ? h[l - 1] : 0);
}

bool operator < (const ts &a, const ts &b){
	int res = 0, l = 1, r = min(len[a.a] - a.b, len[b.a] - b.b);
	while(l <= r){
		int mid = (l + r) / 2;
		if(geth(h[a.a], a.b, a.b + mid - 1) * p[maxlen - a.b] == geth(h[b.a], b.b, b.b + mid - 1) * p[maxlen - b.b]){
			res = mid;
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	if(res == len[b.a] - b.b){
		return false;
	}
	if(res == len[a.a] - a.b){
		return true;
	}
	return s[a.a][a.b + res] < s[b.a][b.b + res];
}

inline int clone(int v){
	rmq[++sz] = rmq[v];
	return sz;
}

inline void push(int v, int L, int R){
	rmq[v].val += rmq[v].add;
	if(L < R){
		rmq[v].ls = clone(rmq[v].ls);
		rmq[rmq[v].ls].add += rmq[v].add;
		rmq[v].rs = clone(rmq[v].rs);
		rmq[rmq[v].rs].add += rmq[v].add;
	}
	rmq[v].add = 0;
}

inline void calc(int v){
	rmq[v].val = min(rmq[rmq[v].ls].val, rmq[rmq[v].rs].val);
}

void update(int v, int L, int R, int l, int r, int add){
	push(v, L, R);
	if(L > r || R < l){
		return;
	}
	if(L >= l && R <= r){
		rmq[v].add += add;
		push(v, L, R);
		return;
	}
	int M = (L + R) / 2;
	update(rmq[v].ls, L, M, l, r, add);
	update(rmq[v].rs, M + 1, R, l, r, add);
	calc(v);
}

int get(int v, int L, int R, int l, int r){
	if(L > r || R < l){
		return inf;
	}
	if(L >= l && R <= r){
		return rmq[v].val + rmq[v].add;
	}
	int M = (L + R) / 2;
	int res = min(get(rmq[v].ls, L, M, l, r), get(rmq[v].rs, M + 1, R, l, r)) + rmq[v].add;
	return res;
}

int main(){
#ifdef HOME
	double start = clock();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
#endif
	//cout << (sizeof(rmq)) / 1024 / 1024 << endl;
	/*cout << "1 1" << endl;
	for(int i = 0; i < 100000; i++){
		cout << char('a' + rand() % 26);
	}
	cout << endl;
	return 0;*/
	int n, k;
	scanf("%d %d", &n, &k);
	p[0] = 1;
	for(int i = 1; i <= maxlen; i++){
		p[i] = p[i - 1] * hx;
	}
	for(int i = 0; i < n; i++){
		scanf("%s", buf);
		len[i] = strlen(buf);
		s[i] = (char*)malloc(sizeof(char) * (len[i] + 1));
		strcpy(s[i], buf);
		h[i] = (ll*)malloc(sizeof(ll) * len[i]);
		for(int j = 0; j < len[i]; j++){
			h[i][j] = (j > 0 ? h[i][j - 1] : 0) + p[j] * s[i][j];
		}
	}
	int m = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < len[i]; j++){
			suff[m].a = i;
			suff[m++].b = j;
		}
	}
	sort(suff, suff + m);
	for(int i = 0; i < n; i++){
		last[i] = -1;
	}
	int maxv = 1;
	while(maxv < m){
		maxv *= 2;
	}
	sz = 2 * maxv - 1;
	for(int i = 1; i < maxv; i++){
		rmq[i].ls = i * 2;
		rmq[i].rs = i * 2 + 1;
	}
	int cur = 1;
	for(int i = 0; i < m; i++){
		cur = clone(cur);
		update(cur, 0, maxv - 1, last[suff[i].a] + 1, i, 1);
		cv[i] = cur;
		last[suff[i].a] = i;
	}
	for(int i = 0; i < m; i++){
		int res = 0, l = 1, r = len[suff[i].a] - suff[i].b;
		while(l <= r){
			int mid = (l + r) / 2;
			ll needh = geth(h[suff[i].a], suff[i].b, suff[i].b + mid - 1) * p[maxlen - suff[i].b];
			int gl = i, cl = 0, cr = i - 1;
			while(cl <= cr){
				int cm = (cl + cr) / 2;
				if(suff[cm].b + mid - 1 >= len[suff[cm].a]){
					cl = cm + 1;
					continue;
				}
				if(geth(h[suff[cm].a], suff[cm].b, suff[cm].b + mid - 1) * p[maxlen - suff[cm].b] == needh){
					gl = cm;
					cr = cm - 1;
				}
				else{
					cl = cm + 1;
				}
			}
			int gr = i;
			cl = i + 1;
			cr = m - 1;
			while(cl <= cr){
				int cm = (cl + cr) / 2;
				if(suff[cm].b + mid - 1 >= len[suff[cm].a]){
					cr = cm - 1;
					continue;
				}
				if(geth(h[suff[cm].a], suff[cm].b, suff[cm].b + mid - 1) * p[maxlen - suff[cm].b] == needh){
					gr = cm;
					cl = cm + 1;
				}
				else{
					cr = cm - 1;
				}
			}
			if(get(cv[gr], 0, maxv - 1, gl, gl) >= k){
				res = mid;
				l = mid + 1;
			}
			else{
				r = mid - 1;
			}
		}
		ans[suff[i].a] += res;
	}
	for(int i = 0; i < n; i++){
		if(i > 0){
			printf(" ");
		}
		printf("%I64d", ans[i]);
	}
	printf("\n");
	return 0;
}