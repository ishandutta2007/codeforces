#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int NN = 1 << 12;
const int M = 2007;
const int N = 12;

int dp[N][NN];
int mx_t[NN];

void solve() {
	int n, m;
	cin >> n >> m;
	vector <vector <int> > a(n, vector <int> (m, 0));
	vector <vector <int> > col(m);
	vector <pair <int, int> > mx(m, {0, 0});
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			col[j].push_back(a[i][j]);
			mx[j] = max(mx[j], {a[i][j], j});
			//cout << i << " " << j << " " << a[i][j] << "\n";
		}
	}
	if (n < m) {
		sort(mx.rbegin(), mx.rend());
		vector <vector <int> > ncol(n);
		for (int i = 0; i < n; i++) {
			ncol[i] = col[mx[i].second];
		}
		col = ncol;
		m = n;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (1 << n); j++) {
			dp[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		for (int sh = 0; sh < n; sh++) {
			for (int mask = 0; mask < (1 << n); mask++) {
				for (int bt = 0; bt < n; bt++) {
					if ((1 << bt) & mask) continue;
					dp[sh][mask | (1 << bt)] = max(dp[sh][mask | (1 << bt)], dp[sh][mask] + col[i][(sh + bt >= n ? sh + bt - n : sh + bt)]);
				}
			}
			//cout << dp.back() << "\n";
		}
		for (int j = 0; j < NN; j++) {
			mx_t[j] = 0;
		}
		for (int j = 0; j < n; j++) {
			for (int mk = 0; mk < 1 << n; mk++) {
				mx_t[mk] = max(mx_t[mk], dp[j][mk]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < (1 << n); j++) {
				dp[i][j] = mx_t[j];
			}
		}
	}
	cout << dp[0][(1 << n) - 1] << "\n";
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