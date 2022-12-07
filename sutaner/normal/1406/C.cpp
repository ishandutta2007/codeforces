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
int g1 = -1, g2 = -1, s[maxn];
void dfs(int x, int fa){
	s[x] = 1; bool f = 1;
	erep(i, x){
		int op = e[i].to;
		if (op == fa) continue;
		dfs(op, x);
		s[x] += s[op];
		if (s[op] > (n >> 1)) f = 0;
	}
	if (n - s[x] > (n >> 1)) f = 0;
	if (f) {
		if (g1 == -1) g1 = x;
		else g2 = x;
	}
}
pii dfs2(int x, int fa){
	bool leaf = 1;
	erep(i, x) {
		int op = e[i].to;
		if (op == fa) continue;
		return dfs2(op, x); 
	} 
	return pii(x, fa);
}
inline void recover(){
	rep(i, 1, n) h[i] = 0; cnt = 1; g1 = g2 = -1;
} 
int main(){
	int T, x, y; read(T);
	while (T--){
		read(n);
		rep(i, 2, n) read(x), read(y), Add_Edge(x, y);
		if (n & 1) {
			printf("%d %d\n%d %d\n", x, y, x, y); 
		}
		else {
			dfs(1, 0);
			if (g2 == -1) {
				printf("%d %d\n%d %d\n", x, y, x, y);
			}
			else {
				pii op = dfs2(g2, g1);
				printf("%d %d\n", op.fi, op.se);
				printf("%d %d\n", op.fi, g1);
			}
		}
		done:recover();
	} 
	return 0;
}