#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector <vector <int> > dp(n, vector <int> (n + 1, -1));
	for (int i = 0; i < n; i++) {
		dp[i][i + 1] = a[i];
	}
	for (int len = 2; len <= n; len++) {
		for (int l = 0; l < n; l++) {
			int r = l + len;
			if (r > n) break;
			for (int i = l + 1; i < r; i++) {
				if (dp[l][i] != -1 && dp[l][i] == dp[i][r]) {
					dp[l][r] = dp[l][i] + 1;
					//cout << l << " " << r << " " << dp[l][r] << "\n";
					break;
				}
			}
		}
	}
	vector <int> pmin(n + 1, n + 7);
	pmin[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (dp[j][i + 1] == -1) continue;
			pmin[i + 1] = min(pmin[i + 1], pmin[j] + 1);
		}
	}
	cout << pmin[n] << "\n";

}