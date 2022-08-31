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
vi eg[maxn];
int tp[maxn];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			tp[i] = 2, eg[i].clear();
		for (int i = 1; i <= m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			eg[u].pb(v);
		}
	//	for (int i = 1; i <= n; i++)
	//		sort(eg[i].begin(), eg[i].end());
		vi res;
		for (int i = 1; i <= n; i++) {
			if (!tp[i]) res.pb(i);
			else {
				for (auto v : eg[i])
					chkmin(tp[v], tp[i] - 1);
			}
		}
		assert(res.size() <= 4 * n / 7);
		printf("%d\n", res.size());
		for (auto v : res) printf("%d ", v);
		printf("\n");
	}
	return 0;
}