#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector <vector <int> > a(n, vector <int> (m, 0));
	vector <vector <int> > col(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			col[j].push_back(a[i][j]);
			//cout << i << " " << j << " " << a[i][j] << "\n";
		}
	}
	vector <int> dp(1 << n, 0);
	for (int i = 0; i < m; i++) {
		vector <int> ndp = dp;
		for (int sh = 0; sh < n; sh++) {
			for (int m1 = (1 << n) - 1; m1 >= 0; m1--) {
				for (int m2 = (1 << n) - 1; m2 >= 0; m2--) {
					if (m1 & m2) continue;
					int add = 0;
					for (int j = 0; j < n; j++) {
						if (!((1 << j) & m2)) continue;
						add += col[i][(j + sh) % n];
					}
					//cout << m2 << " " << i << " " << add << "\n";
					ndp[m1 | m2] = max(ndp[m1 | m2], dp[m1] + add);
				}
			}
			//cout << dp.back() << "\n";
		}
		dp = ndp;
	}
	cout << dp.back() << "\n";
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}

}