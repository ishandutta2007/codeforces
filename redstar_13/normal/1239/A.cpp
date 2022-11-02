#include<bits/stdc++.h>

#define pb push_back
#define x first
#define y second
using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
typedef vector<int> VI;
int power(int a, int b, int m, int ans=1) {
	for(; b; b>>=1, a=1LL*a*a%m) if(b&1) ans=1LL*ans*a%m;
	return ans;
}

const int NN =100111;
const int mod = 1000000007;
int dp[NN];

inline void add(int &u, int v) {
	u += v;
	if(u >= mod) u -= mod;
}

int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	dp[0] = 2;
	dp[1] = 2;
	for(int i=2; i<=max(n, m); i++) dp[i] = (dp[i-1] + dp[i-2]) % mod;
	int ans = 2;
	for(int i=1; i<n; i++) add(ans, dp[n-i-1]);
	for(int i=1; i<m; i++) add(ans, dp[m-i-1]);
	cout << ans << endl;
	return 0;
}