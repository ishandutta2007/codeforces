#include <bits/stdc++.h>

using namespace std;

using llint = long long;
const int INF = 1000000007;
int b[105][105], a[105][105], an;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
vector<pip> V;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int Tc;
	for (cin >> Tc; Tc--; ) {
		int n, m;
		cin >> n >> m;
		V.clear();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> b[i][j];
				V.push_back({b[i][j], {i, j}});
			}
		}
		memset(a, -1, sizeof a);
		sort(V.begin(), V.end());
		an = 0;
		for (auto v : V) {
			pii p = v.second;
			if (b[p.first][p.second] == -1) continue;
			a[p.first][an] = b[p.first][p.second];
			b[p.first][p.second] = -1;
			for (int i = 0; i < n; i++) {
				if (i == p.first) continue;
				int id, mx = -1;
				for (int j = 0; j < m; j++) if (mx < b[i][j]) {
					mx = b[i][j];
					id = j;
				}
				assert(mx != -1);
				a[i][an] = b[i][id];
				b[i][id] = -1;
			}
			an++;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) cout << a[i][j] << ' ';
			cout << endl;
		}
	}
	
	return 0;
}