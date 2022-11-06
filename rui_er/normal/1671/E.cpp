// LUOGU_RID: 92700454
//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 1 << 18, mod = 998244353;

ll n, dp[N];
string s, mn[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld", &n);
	cin >> s;
	n = (1 << n) - 1;
	per(i, n, 1) {
		if(i > (n - 1) / 2) {
			mn[i] = s[i-1];
			dp[i] = 1;
		}
		else {
			if(mn[2*i] == mn[2*i+1]) dp[i] = dp[2*i] * dp[2*i+1] % mod;
			else dp[i] = 2 * dp[2*i] % mod * dp[2*i+1] % mod;
			if(mn[2*i] < mn[2*i+1]) mn[i] = s[i-1] + mn[2*i] + mn[2*i+1];
			else mn[i] = s[i-1] + mn[2*i+1] + mn[2*i];
		}
	}
	printf("%lld\n", dp[1]);
	return 0;
}