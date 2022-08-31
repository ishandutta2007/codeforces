//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 3005 /*rem*/
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
int dp[maxn][maxn];
char s[maxn];
char t[maxn];
int n, m;
int main() {
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	n = strlen(s + 1), m = strlen(t + 1);
	ll ans = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 1; j <= m + 1; j++) {
			if (i == 0) dp[i][j] = 1;
			else {
				if (j == m + 1) {
					dp[i][j] = 2 * dp[i - 1][j] % mod;
				}
				else {
					if (s[i] == t[j])
						dp[i][j] = dp[i - 1][j + 1];
					
						// 
					int nl = m + 1 - j;
					int rs = 0;
					if (i > nl) rs = dp[i - 1][j];
					else {
						int ed = j + i - 1;
						if (s[i] == t[ed]) rs = dp[i - 1][j];
					} 
					dp[i][j] += rs;
					dp[i][j] %= mod;
				}
			}
		//	cout << i << ' ' << j << ' ' << dp[i][j] << endl;
			if (i >= m && j == 1)
				ans += dp[i][j], ans %= mod;
		}
	cout << ans << endl;
	return 0;
}