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

const int NN = 200011;
int a[NN];
int dp[NN][2];
	INT ans[2];


int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n;
	cin >> n;
	for(int i=1; i<=n; i++) scanf("%d", a+i);
	for(int i=1; i<=n; i++) {
		if(a[i] > 0) dp[i][0] = dp[i-1][0] + 1, dp[i][1] = dp[i-1][1];
		else dp[i][0] = dp[i-1][1], dp[i][1] = dp[i-1][0] + 1;
		ans[0] += dp[i][0];
		ans[1] += dp[i][1];
	}
	cout << ans[1] << ' ' << ans[0] << endl;
	return 0;
}