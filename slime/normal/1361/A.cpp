#include <bits/stdc++.h>
using namespace std;
#define maxn 500010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 1000000007
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
int n, m;
vi eg[maxn];
int fl[maxn];
int t[maxn];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		eg[u].pb(v), eg[v].pb(u);
	}
	vector<pi> res;
	for (int i = 1; i <= n ;i++)
		scanf("%d", &t[i]), 
		res.pb(mp(t[i], i));
	sort(res.begin(), res.end());
	for (int i = 1; i <= n; i++) {
		for (auto v : eg[i])
			fl[t[v]] = 1;
		int pl = 1;
		while (fl[pl]) pl++;
	//	cout 
		if (pl != t[i]) {
			cout << -1 << endl;
			return 0;
		}
		for (auto v : eg[i])
			fl[t[v]] = 0;
	}
	for (auto x : res)
		printf("%d ", x.se);
	cout << endl;
	return 0;
}