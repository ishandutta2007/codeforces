#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int INF = 1e9 + 7;

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector <vector <int> > g(m, vector <int> (m, 0));
	for (int i = 1; i < n; i++) {
		int x = s[i - 1] - 'a', y = s[i] - 'a';
		if (x != y) {
			g[x][y]++;
			g[y][x]++;
		}
	}
	vector <int> dp(1 << m, INF);
	dp[0] = 0;
	for (int mask = 0; mask < (1 << m); mask++) {
		//cout << mask << " " << dp[mask] << "\n";
		int cnt = __builtin_popcount(mask);
		for (int i = 0; i < m; i++) {
			if (mask & (1 << i)) continue;
			int mask_ = mask | (1 << i);
			int cnt_e = 0, cnt_u = 0;
			for (int j = 0; j < m; j++) {
				if (mask & (1 << j)) {
					cnt_e += g[i][j];
				} else {
					cnt_u += g[i][j];
				}
			}
			dp[mask_] = min(dp[mask_], dp[mask] + cnt_e * (cnt + 1) - cnt_u * (cnt + 1));
		}
	}
	cout << dp.back() << "\n";

}