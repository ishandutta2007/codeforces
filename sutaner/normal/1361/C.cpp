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
#define maxn 600020
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
int a[maxn], b[maxn];
int num[1 << 21];

struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 3];
bool vis[maxn << 3];
int cnt = 1, h[1 << 22], cur[1 << 22];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
	if (!x || !y) assert(false);
}
int res[maxn << 3], cs = 0;
void dfs(int x){	
	erep2(i, x){
		if (vis[i]) continue;
		int _i = i;
		int op = e[i].to;
		vis[i] = vis[i ^ 1] = 1;
		dfs(op);
		res[++cs] = _i;
	}
} 

int out[maxn << 1], co = 0;
bool build(int ans){
	co = 0;
	
	
	int bas = (n << 1 | 1), sig = (1 << ans) - 1;;
	rep(i, 1, n){
		int x = a[i] & sig;
		Add_Edge((i - 1) << 1 | 1, bas + x);
		x = b[i] & sig; 
		Add_Edge(i << 1, bas + x);
		Add_Edge(i << 1, (i - 1) << 1 | 1);
	} 
	srep(i, 1, (1 << ans) + bas) cur[i] = h[i]; 
	srep(i, 0, (1 << ans)) if (num[i]) {dfs(i + bas); break;}
	rep(i, 1, cs) {
		int x = e[res[i]].to;
		if (x <= (n << 1)) out[++co] = x;
	}  
	
	srep(i, 1, (1 << ans) + bas) cur[i] = h[i] = 0;
	rep(i, 1, cnt) vis[i] = 0;
	cnt = 1;
	cs = 0;
	
	if (co != (n << 1)) return false;
	
	return true;
}

int main(){
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d%d", a + i, b + i);
	int ctodd = 0, sig = 0;
	per(ans, 20, 0){
		ctodd = 0;
		sig = (1 << ans) - 1;
		rep(i, 1, n){
			int x = a[i] & sig;
			num[x]++;
			if (num[x] & 1) ctodd++;
			else ctodd--;
			x = b[i] & sig;
			num[x]++;
			if (num[x] & 1) ctodd++;
			else ctodd--;
		} 
		if (ctodd == 0){
			//printf("%d\n", ans);
			if (build(ans)) {
				printf("%d\n", ans);
				rep(i, 1, co) printf("%d ", out[i]);
				return 0;
			}
			
		}
		rep(i, 1, n){	
			int x = a[i] & sig;
			num[x]--; 
			x = b[i] & sig;
			num[x]--; 
		}
	} 
	return 0;
}