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

const int NN = 2011;
char s[NN][NN];
int dp[NN][NN][2];
int sum[NN][NN][2];
int cnt[NN][NN][2];

const int mod = 1000000007;

inline void add(int &u, int v) {
	u += v;
	if(u >= mod) u -= mod;
}

inline void sub(int &u, int v) {
	u -= v;
	if(u < 0) u += mod;
}

int n, m;

int solve() {
	cin >> n >> m;
	for(int i=1; i<=n; i++) scanf("%s", s[i]+1);
	if(n*m==1) return puts("1");
	if(s[n][m] == 'R') return puts("0");
	for(int i=1; i<=n; i++) {
		for(int j=m; j>=1; j--) {
			cnt[i][j][0] = cnt[i][j+1][0] + (s[i][j] == 'R');
		}
	}
	for(int i=n; i>=1; i--) {
		for(int j=1; j<=m; j++) cnt[i][j][1] = cnt[i+1][j][1] + (s[i][j] == 'R');
	}
	
	for(int i=n; i>=1; i--) {
		for(int j=m; j>=1; j--) {
			if(i == n and j == m) {
				dp[i][j][0] = 1;
				dp[i][j][1] = 1;
				sum[i][j][0] = 1;
				sum[i][j][1] = 1;
				continue;
			}
			if(i<n) {
				int r = cnt[i][j+1][0];
				dp[i][j][0] = sum[i][j+1][0];
				sub(dp[i][j][0], sum[i][m-r+1][0]);
			}
			else {
				int r = cnt[i][j+1][0];
				if(r == 0) dp[i][j][0] = 1;
			}
			
			if(j<m) {
				int r=cnt[i+1][j][1];
				dp[i][j][1] = sum[i+1][j][1];
				sub(dp[i][j][1], sum[n-r+1][j][1]);
			}
			else {
				int r = cnt[i+1][j][1];
				if(r == 0) dp[i][j][1] = 1;
			}
		//	cout << i << ' ' << j << ' ' << dp[i][j][0] << ' ' << dp[i][j][1] << endl;
			
			sum[i][j][0] = sum[i][j+1][0];
			add(sum[i][j][0], dp[i][j][1]);
			
			sum[i][j][1] = sum[i+1][j][1];
			add(sum[i][j][1], dp[i][j][0]);
		}
	}
	int ans = 0;
	if(m>1) add(ans, dp[1][1][0]);
	if(n>1) add(ans, dp[1][1][1]);
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