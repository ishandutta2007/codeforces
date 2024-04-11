#include <bits/stdc++.h>
using namespace std;
bool dp[10002][2002];
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;
		vector<int> a(n);

		for (int i = 0; i < n; i ++)
			cin >> a[i];
		
		int l = a[0]-1, r = 2000 + 1;

		auto f = [&](int L) {
			memset(dp[n-1],0,sizeof(dp[n-1]));
			for (int i = a[n-1]; i <= L; i ++) dp[n-1][i] = 1;
			for (int i = 0; i <= L-a[n-1]; i ++) dp[n-1][i] = 1;
			for (int i = n-2;i>=0;i--) {
				for (int j=0;j<=L;j++){
					if(j+a[i]<=L && dp[i+1][j+a[i]]) dp[i][j]=1;
					else if(j-a[i]>=0 && dp[i+1][j-a[i]]) dp[i][j]=1;
					else dp[i][j]=0;
				}
			}
			for(int i=0;i<=L;i++) if(dp[0][i]) return 1;
			return 0;
		};

		while (r - l > 1) {
			int m = (l+r)>>1;
			if (f(m)) {
				r = m;
			} else {
				l = m;
			}
		}
		cout << r << "\n";
	}		
}
/*
L
dp[i][j]
*/