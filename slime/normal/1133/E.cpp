#include <bits/stdc++.h>
#define ll long long
#define maxn 5005 /*rem*/
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
int dp[maxn][maxn]; 
int a[maxn];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int pl = n;
	for (int i = n; i >= 1; i--) {
		while (a[pl] > a[i] + 5) pl--;
		for (int j = 1; j <= k; j++)
			dp[i][j] = max(dp[i + 1][j], dp[pl + 1][j - 1] + (pl + 1 - i));
	}
	cout << dp[1][k] << endl;
	return 0;
}