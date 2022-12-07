#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pii pair<int, int>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 300020
#define maxm 400020
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

int n, m, k;
int a[maxn];
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxm << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
}
int d1[maxn];
int dn[maxn];
int bfs[maxn];
int he = 0, ta = 0;
void BFS(int s, int* d){
	rep(i, 1, n) d[i] = m + 1;
	d[s] = he = ta = 0;
	bfs[++he] = s;
	int x, y;
	while (he > ta){
		x = bfs[++ta];
		erep(i, x){
			y = e[i].to;
			if (d[y] == m + 1) d[y] = d[x] + 1, bfs[++he] = y;
		}
	}
}

struct ele{
	int x;
	ele(int x) : x(x){}
	ele(){}
	bool operator < (const ele b) {
		return d1[x] - dn[x] < d1[b.x] - dn[b.x];
	}
}lis[maxn];

int main(){
	
		//freopen("in2.txt", "r", stdin);
		
	//ios :: sync_with_stdio(false), cin.tie(0);
		
	int x, y;
	read(n), read(m), read(k);
	rep(i, 1, k) read(a[i]);
	rep(i, 1, m) read(x), read(y), Add_Edge(x, y); 
	BFS(1, d1), BFS(n, dn);
	assert(d1[n] == dn[1]);
	int ans = d1[n];
	rep(i, 1, k) lis[i] = a[i];
	sort(lis + 1, lis + 1 + k);
	int mxd1 = 0, mx = 0;
	rep(i, 1, k){
		if (i > 1) mx = max(mx, mxd1 + 1 + dn[lis[i].x]); 
		mxd1 = max(mxd1, d1[lis[i].x]);
	} 
	write(min(ans, mx));
	return 0;
}