#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 400020
#define ll long long int 
using namespace std;

int n, m;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 3];
int cnt = 1, h[maxn], in[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
	in[y]++;
} // i & 1 -> reverse

int d[maxn];
int bfs[maxn], head = 0, tail = 0;
int lis[maxn], cs = 0;
bool ok[maxn];
void topo_sort(){ 
	rep(i, 1, n) if (!in[i]) bfs[++head] = i; 
	while (head > tail){
		int x = bfs[++tail];
		lis[++cs] = x;
		erep(i, x){
			if (i & 1) continue;
			int op = e[i].to;
			in[op]--;
			if (!in[op]) bfs[++head] = op;
		}
	}
	rep(i, 1, n){
		int x = lis[i];
		erep(j, x){
			if (j & 1){
				int op = e[j].to;
				if (ok[op] && d[op] == 1) goto fail; 
			}
		}
		ok[x] = 1;
		erep(j, x){
			if (j & 1){
				int op = e[j].to;
				if (ok[op]) d[x] = max(d[x], d[op] + 1); 
			}
		}
		fail:;
	}
	int ct = 0;
	rep(i, 1, n) if (!ok[i]) ct++;
	printf("%d\n", ct);
	rep(i, 1, n) if (!ok[i]) printf("%d ", i);
	printf("\n");
}

void recover(){
	cs = head = tail = 0; cnt = 1;
	rep(i, 1, n) h[i] = in[i] = d[i] = ok[i] = 0;
}

int main(){
	int T, x, y;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		rep(i, 1, m) scanf("%d%d", &x, &y), Add_Edge(x, y);
		topo_sort();
		recover();
	}
	return 0;
}