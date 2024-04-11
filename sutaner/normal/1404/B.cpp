#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 200020
#define maxm
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}

int n;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
}
int d[maxn];
void dfs(int x, int fa){
	erep(i, x) {
		int op = e[i].to;
		if (op == fa) continue;
		d[op] = d[x] + 1;
		dfs(op, x);
	}
}

int main(){
	int T, x, y, a, b, da, db; scanf("%d", &T);
	while (T--){
		int mx = -1, mx2 = -1;
		scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
		rep(i, 2, n) scanf("%d%d", &x, &y), Add_Edge(x, y);
		d[a] = 0, dfs(a, 0);
		if (d[b] <= da) {
			printf("Alice\n");
			goto done;
		}
		d[1] = 0, dfs(1, 0); 
		rep(i, 1, n) if (d[i] > mx) mx = d[i], mx2 = i; 
		d[mx2] = 0, dfs(mx2, 0);
		mx = -1; rep(i, 1, n) mx = max(mx, d[i]);
		if (da >= ((mx + 1) >> 1)) {
			printf("Alice\n");
			goto done;
		}
		if (db >= 2 * da + 1) {
			printf("Bob\n");
			goto done;
		}
		else {
			printf("Alice\n");
			goto done;
		} 
		done: rep(i, 1, n) h[i] = 0; cnt = 1;
	}
	return 0;
}