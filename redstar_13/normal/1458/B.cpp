#include <bits/stdc++.h>

#define pb push_back
#define x first
#define y second
using namespace std;

using INT = long long;
using pii = pair<int, int>;

const int NN = 111;
int dp[2][NN][10011];
int a[NN],b[NN];

inline void smax(int &u, int v) {
	if(u<v) u = v;
}


inline void smax(double &u, double v) {
	if(u<v) u = v;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	ios_base :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a[i] >> b[i];
	}
	memset(dp, -0x3f, sizeof dp);
	dp[0][0][0] = 0;
	int s = 0;
	int S = 0;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=i; j++) {
			for(int k=0; k<=s; k++) if(dp[0][j][k] > -1) {
//				cerr<<i<<' '<<j<<' '<<k<<endl;
				smax(dp[1][j][k], dp[0][j][k]);
				smax(dp[1][j+1][k+a[i]], dp[0][j][k] + b[i]);
			}
		}
		S += b[i];
		s += a[i];
		for(int j=0; j<=i; j++) {
			for(int k=0; k<=s; k++) dp[0][j][k] = dp[1][j][k], dp[1][j][k] = -1e8;	
		}
	}
	for(int i=1; i<=n; i++) {
		double ans = 0;
		for(int j=0; j<=s; j++) {
			double tmp = dp[0][i][j];
			smax(ans, min((S+tmp)/2.0, j/1.0));
		}
		cout << ans << endl;
	}
}