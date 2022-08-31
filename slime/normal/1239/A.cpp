#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
ll dp[maxn]; 
int main() {
	dp[0] = 1;
	for (int i = 1; i < maxn; i++) {
		dp[i] = dp[i - 1];
		if (i >= 2) dp[i] = (dp[i] + dp[i - 2]) % mod;
	}
	int n, m;
	cin >> n >> m;
	ll ans = (dp[n] + dp[m] - 1) * 2;
	ans %= mod;
	if (ans < 0) ans += mod;
	cout << ans << endl;
	return 0;
}