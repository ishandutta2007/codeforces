//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
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
int fa[maxn], dep[maxn];
vi eg[maxn];
void dfs(int a) {
	for (auto v : eg[a]) {
		if (v == fa[a]) continue;
		fa[v] = a, dep[v] = dep[a] + 1, dfs(v);
	}
}
int cnt[maxn];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		eg[u].pb(v), eg[v].pb(u);
	}
	int a0 = 1, a1 = 0;
	for (int i = 1; i <= n; i++) {
		if (eg[i].size() >= 2) {
			dfs(i);
			break;
		}
	}
	int u[2] = {0, 0};
	for (int i = 1; i <= n; i++)
		if (eg[i].size() == 1) 
			cnt[fa[i]]++, u[dep[i] % 2] = 1;
	if (u[0] && u[1]) a0 = 3;
	a1 = n - 1;
	for (int i = 1; i <= n; i++)
		if (cnt[i] >= 2) a1 -= cnt[i] - 1;
	printf("%d %d\n", a0, a1);
	return 0;
}