#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define int ll
#define pb push_back
#define kek pop_back
#define mp make_pair
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int INF = 1e18 + 666;
 
template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
 
template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
 
void run();
 
signed main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	run();
}

void run() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> mt(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> mt[i][j];
		}
	}
	vector<vector<int>> res(n, vector<int>(m, 0));
	vector<pii> ans;
	for (int i = 0; i + 1 < n; ++i) {
		for (int j = 0; j + 1 < m; ++j) {
			if (mt[i][j] == mt[i + 1][j] && mt[i][j] == mt[i][j + 1] && mt[i][j] == mt[i + 1][j + 1] && mt[i][j] == 1) {
				ans.pb({i, j});
				res[i][j] = res[i + 1][j] = res[i][j + 1] = res[i + 1][j + 1] = 1;
			}
		}
	}
	if (res == mt) {
		cout << len(ans) << endl;
		for (auto &[x, y] : ans) {
			cout << x + 1 << " " << y + 1 << endl;
		}
	} else {
		cout << -1 << endl;
	}
}