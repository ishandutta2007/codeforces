#include<bits/stdc++.h>
using namespace std;
typedef long long INT;
#define NN 100011
int n, m;
char s[NN];
int cnt[NN];
INT ans;
int dp[NN];
int calc() {
	int c=0;
	for(int i=1; i<n; i++) {
		c+=s[i]!=s[i+1];
		ans+=c;
	}
}
int solve() {
	cin >> n >> m;
	scanf("%s", s+1);
	calc();
	reverse(s+1, s+n+1);
	calc();
	ans += n;
	ans *= m-1;
	for(int i=2; i<=n; i++) if(s[i] != s[i-1]) {
		if(s[i] == s[i-2]) dp[i] = dp[i-1]+1;
		else dp[i] = 2;
		if(dp[i]) ans -= dp[i]-1;
	}
	cout << ans << endl;
}
int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	solve();
	return 0;
}