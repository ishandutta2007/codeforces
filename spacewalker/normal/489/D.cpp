#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m; cin >> n >> m;
	vector<pair<int, int>> elist(m, make_pair(0, 0));
	vector<vector<int>> adjmat(n, vector<int>(n, 0));
	for (int i = 0; i < m; ++i) {
		cin >> elist[i].first >> elist[i].second;
		--elist[i].first; --elist[i].second;
		adjmat[elist[i].first][elist[i].second] = 1;
	}
	vector<vector<int>> table(n, vector<int>(n, 0));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (adjmat[elist[i].second][j] == 1 && elist[i].first != j) {
				++table[elist[i].first][j];
				//cout << "path found: " << elist[i].first << " " << elist[i].second << " " << j << endl;
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ans += (ll)table[i][j] * (table[i][j] - 1) / 2;
		}
	}
	cout << ans << endl;
	return 0;	
}