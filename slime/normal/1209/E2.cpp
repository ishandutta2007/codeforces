#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
} 	
int n, m;
struct th {
	int num[13], mx;
	void upd() {
		mx = 0;
		for (int i = 0; i < n; i++)
			mx = max(mx, num[i]);
	}
	bool operator < (const th &u)const {
		return mx > u.mx;
	}
}p[maxn];
int dp[20][4097];
int ns[4097];
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		scanf("%d%d", &n, &m);
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
				scanf("%d", &p[k].num[j]);
		for (int k = 0; k < m; k++) {
			p[k].mx = 0;
			for (int j = 0; j < n; j++)
				p[k].mx = max(p[k].mx, p[k].num[j]);
		}
		sort(p, p + m);
		memset(dp, 0, sizeof(dp));
		int ed = min(m, n);
		for (int i = ed - 1; i >= 0; i--) {
			memset(ns, 0, sizeof(ns));
			for (int s = 0; s < n; s++) 
				for (int u = 0; u < (1 << n); u++) {
					int nans = 0;
					for (int t = 0; t < n; t++) 
						if (u & (1 << t)) nans += p[i].num[(t + s) % n]; 
					ns[u] = max(ns[u], nans);
				}
			for (int j = 0; j < (1 << n); j++) {
				for (int k = j; 1; k = (k - 1) & j) {
					dp[i][j] = max(dp[i][j], dp[i + 1][k] + ns[j ^ k]);
					if (!k) break;
				}
			}
		}
		cout << dp[0][(1 << n) - 1] << endl;
	}
	return 0;
}