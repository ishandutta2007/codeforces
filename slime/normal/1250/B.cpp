#include <bits/stdc++.h>
using namespace std;
#define maxn 305
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
#define fi first
#define se second
#define mp make_pair
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
int tr[maxn];
vi sr;
int dp[maxn][maxn];
pair<int, int> th[maxn];
int gt(int pl) {
	return lower_bound(sr.begin(), sr.end(), pl) - sr.begin();
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &th[i].fi, &th[i].se), 
		sr.pb(th[i].fi + th[i].se),
		sr.pb(th[i].fi - th[i].se), 
		sr.pb(th[i].fi);
	sort(th + 1, th + n + 1);
	sort(sr.begin(), sr.end());
	/*
	for (int j = 0; j < sr.size(); j++)
		cout << sr[j] << ' ';
	cout << endl;
	for (int i = 1; i <= n; i++)
		cout << th[i].fi << ' ' << th[i].se << endl;
*/	for (int i = 0; i <= n; i++)
		for (int j = 0; j < sr.size(); j++) {
			if (i == 0) dp[i][j] = 0;
			else {
				int nx =  gt(th[i].fi - th[i].se);
				int ndis = max(0, min(sr[j], th[i].fi) - sr[nx]);
				dp[i][j] = max(dp[i][j], ndis + dp[i - 1][min(nx, j)]);
				int mn = j;
				for (int k = i; k >= 1; k--) {
					int us = min(mn, gt(th[k].fi));
					int ndis = max(0, min(sr[j], th[k].fi + th[k].se) - sr[us]);
					dp[i][j] = max(dp[i][j], ndis + dp[k - 1][us]);
					mn = min(mn, gt(th[k].fi - th[k].se));
				}
			}
		//	cout << i << ' ' << sr[j] << ' ' << dp[i][j] << endl;
		}
	cout << dp[n][sr.size() - 1] << endl;
	return 0;
}