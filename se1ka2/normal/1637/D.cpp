#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 10000000000000;

ll dp[102][20002];

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		ll a[102], b[102];
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < n; i++) cin >> b[i];
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= 20000; j++) dp[i][j] = INF;
		}
		dp[0][0] = 0;
		ll s = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j <= s; j++){
				dp[i + 1][j + a[i]] = min(dp[i + 1][j + a[i]], dp[i][j] + (j * a[i] + (s - j) * b[i]) * 2);
				dp[i + 1][j + b[i]] = min(dp[i + 1][j + b[i]], dp[i][j] + (j * b[i] + (s - j) * a[i]) * 2);
			}
			s += a[i] + b[i];
		}
		ll t = 0;
		for(int i = 0; i < n; i++) t += (a[i] * a[i] + b[i] * b[i]) * (n - 1);
		ll ans = INF;
		for(int j = 0; j <= s; j++) ans = min(ans, t + dp[n][j]);
		cout << ans << endl;
	}
}