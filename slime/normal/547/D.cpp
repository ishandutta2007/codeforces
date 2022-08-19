#include <bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
#define fi first
#define pi pair<int, int>
#define se second
#define mp make_pair
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
int x[2][maxn];
vi eg[2][maxn];
int fa[maxn], col[maxn];
int gfa(int a) {
	if (a == fa[a]) return a;
	int ns = gfa(fa[a]);
	col[a] ^= col[fa[a]];
	fa[a] = ns;
	return ns;
}
int main() {
	int n;
	for (int i = 0; i < maxn; i++)
		fa[i] = i;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &x[0][i], &x[1][i]);
		eg[0][x[0][i]].pb(i), eg[1][x[1][i]].pb(i);
	}
	for (int tp = 0; tp < 2; tp++)
		for (int i = 0; i < maxn; i++) {
			if (eg[tp][i].size() <= 1) continue;
	//		cout << "!!!" << tp << ' ' << i << ' ' << eg[tp][i].size() << endl;
			for (int j = 0; j < eg[tp][i].size() - 1; j += 2) {
				int x = eg[tp][i][j], y = eg[tp][i][j + 1];
				int xfa = gfa(x), yfa = gfa(y);
				if (xfa == yfa) continue;
				fa[xfa] = yfa, col[xfa] = 1 ^ col[y] ^ col[x];
			}
		}
	for (int i = 1; i <= n; i++)
		gfa(i);
	for (int i = 1; i <= n; i++) 
		if (col[i]) printf("r");
		else printf("b");
	return 0;
}