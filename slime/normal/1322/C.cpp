#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int maxn = 500005;
ll r[maxn];
ll c[maxn];
ll w[maxn];
ll gcd(ll a, ll b) {
	if (!b) return a;
	return gcd(b, a % b);
}
int main() {
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		srand((unsigned long long)(new char));
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			c[i] = 0; //  
			r[i] = 0;
			for (int j = 0; j < 61; j++)
				c[i] = c[i] * 2 + (rand() & 1); 
		}
		for (int i = 1; i <= n; i++) 
			scanf("%lld", &w[i]);
		for (int i = 1; i <= m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			r[v] ^= c[u];
		}
		vector<pair<ll, int> >g;
		for (int i = 1; i <= n; i++)
			g.pb(mp(r[i], i));
		sort(g.begin(), g.end());
		ll fn = 0;
		for (int i = 0; i < g.size(); ) {
			int j = i;
			ll s = 0;
			while (j < g.size() && g[j].fi == g[i].fi)
				s += w[g[j].se], j++;
			if (g[i].fi) 
				fn = gcd(fn, s);
			i = j;
		} 
		printf("%lld\n", fn);
	}
	return 0;
}
/*
1 1 0
1 1000000000
1 1000000000
*/