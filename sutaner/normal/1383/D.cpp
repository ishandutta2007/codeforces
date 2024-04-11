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
#define maxn 320
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

int n, m;
int lis[maxn << 1], cs = 0;
bool numr[maxn * maxn], numc[maxn * maxn];
int a[maxn][maxn], res[maxn][maxn];
pii pos[maxn << 1]; int cp = 0;
int main(){
	scanf("%d%d", &n, &m);
	rep(i, 1, n) rep(j, 1, m) scanf("%d", &a[i][j]); 
	rep(i, 1, n) {
		int mx = 0;
		rep(j, 1, m) mx = max(mx, a[i][j]);
		lis[++cs] = mx, numr[mx] = 1; 
	}
	rep(j, 1, m) {
		int mx = 0;
		rep(i, 1, n) mx = max(mx, a[i][j]);
		lis[++cs] = mx, numc[mx] = 1; 
	}
	sort(lis + 1, lis + 1 + cs);
	cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
	int x = 1, y = 1;
	per(i, cs, 1){
		int v = lis[i];
		if (i == cs) res[x][y] = v, pos[++cp] = pii(x, y);
		else {
			if (numr[v] && numc[v]) x++, y++, res[x][y] = v, pos[++cp] = pii(x, y);
			else if (numr[v]) {
				x++, res[x][y] = v, pos[++cp] = pii(x, y);
			}
			else if (numc[v]) {
				y++, res[x][y] = v, pos[++cp] = pii(x, y);
			}
			else assert(false);
		}
	}
	int ptr = n * m;
	x = 1, y = 1;
	rep(i, 1, cp){ 
		if (pos[i].fi > x) {
			per(j, pos[i].se - 1, 1){
				while (ptr && (numc[ptr] || numr[ptr])) ptr--; 
				res[pos[i].fi][j] = ptr, ptr--;
			}
		}
		if (pos[i].se > y){ 
			per(j, pos[i].fi - 1, 1) {
				while (ptr && (numc[ptr] || numr[ptr])) ptr--; 
				res[j][pos[i].se] = ptr, ptr--;
			}
		}
		x = pos[i].fi, y = pos[i].se; 
	}
	rep(i, 1, n) {rep(j, 1, m) printf("%d ", res[i][j]); printf("\n");}
	return 0;
}