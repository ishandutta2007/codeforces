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
#define maxn 400020
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



vector<pii> G[maxn], rG[maxn]; 
bool A[10][10][10][10];
int n, m, k, out[maxn];

pii tmp[maxn];
int ct = 0;

int ans = 0;
int now[10];
void dfs(int pos){
	if (pos == k + 1){
		rep(i, 1, k) {
			rep(j, 1, k) { 
				rep(l, 1, j){
					if (!A[i][now[i]][j][l]) continue;
					if (now[j] == l) return;
				}
			}
		}
		ans++;
		return;
	}
	rep(i, 1, pos){
		now[pos] = i;
		dfs(pos + 1);
	}
	now[pos] = 0;
	return;
}

int B[10][10];

int main(){
	int x, y, z;
	read(n), read(m), read(k);
	rep(i, 1, m) read(x), read(y), read(z), G[x].pb(pii(z, y)), rG[y].pb(pii(z, x)), out[x]++;
	rep(i, 1, n) sort(G[i].begin(), G[i].end());
	rep(i, 1, n){
		int si = rG[i].size();
		ct = 0;
		srep(j, 0, si) {
			pii op = rG[i][j];
			int rank = lower_bound(G[op.se].begin(), G[op.se].end(), pii(op.fi, i)) - G[op.se].begin() + 1;
			int deg = out[op.se];
			B[deg][rank]++;
			//tmp[++ct] = pii(deg, rank);
		}
		rep(i, 1, k) rep(j, 1, k) {
			if (!B[i][j]) continue;
			tmp[++ct] = pii(i, j);
			if (B[i][j] > 1) tmp[++ct] = pii(i, j);
			B[i][j] = 0;
		}
		rep(i, 1, ct){
			pii op = tmp[i];
			rep(j, i + 1, ct){
				pii op2 = tmp[j];
				A[op.fi][op.se][op2.fi][op2.se] = 1;
				A[op2.fi][op2.se][op.fi][op.se] = 1;
			}
		}
	}
	dfs(1);
	printf("%d\n", ans);
	return 0;
}