#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e3 + 10;

bool B[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<pair<pll, pll>> ans;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				char c;
				cin >> c;
				B[i][j] = (c == '1');
			}
		}

		if (B[1][1]) {
			cout << -1 << endl;
			continue;
		}

		for (int i = n; i > 0; i--) {
			for (int j = m; j > 0; j--) {
				if (i == 1 && j == 1) continue;
				if (i == 1) {
					if (B[i][j]) ans.push_back({{i, j - 1}, {i, j}});
					else ans.push_back({{i, j}, {i, j}});
				} else {
					if (B[i][j]) ans.push_back({{i - 1, j}, {i, j}});
					else ans.push_back({{i, j}, {i, j}});
				}
			}
		}

		cout << ans.size() << endl;
		for (auto e : ans)
			cout << e.X.X << sep << e.X.Y << sep << e.Y.X << sep << e.Y.Y << endl;
	}
	return 0;
}