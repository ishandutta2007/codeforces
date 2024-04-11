//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
int dep[maxn], sz[maxn];
vi eg[maxn];
void dfs(int a, int fa) {
	sz[a] = 1;
	for (auto v : eg[a]) {
		if (v == fa) continue;
		dep[v] = dep[a] + 1; dfs(v, a);
		sz[a] += sz[v];
	}
}
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		eg[u].pb(v), eg[v].pb(u);
	}
	dep[1] = 1;
	dfs(1, 0);
	vi cur;
	for (int i = 1; i <= n; i++)
		cur.pb(dep[i] - sz[i]);
	sort(cur.begin(), cur.end());
	ll ans = 0;
	for (int j = cur.size() - 1; j >= cur.size() - k; j--)
		ans += cur[j];
	cout << ans << endl;
	return 0;
}