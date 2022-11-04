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
	int n;
	cin >> n;
	vector<vector<int>> mt(n, vector<int>(n, INF));
	for (auto &l : mt) {
		for (auto &x : l) {
			char c;
			cin >> c;
			if (c == '1') {
				x = 1;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		mt[i][i] = 0;
	}
	for (int th = 0; th < n; ++th) {
		for (int fr = 0; fr < n; ++fr) {
			for (int to = 0; to < n; ++to) {
				cmin(mt[fr][to], mt[fr][th] + mt[th][to]);
			}
		}
	}
	int m;
	cin >> m;
	vector<int> p(m);
	for (auto &x : p) {
		cin >> x;
		--x;
	}
	vector<int> ans;
	ans.pb(p[0]);
	int cur_dist = 0;
	for (int i = 1; i < m; ++i) {
		cur_dist += mt[p[i - 1]][p[i]];
		if (cur_dist != mt[ans.back()][p[i]]) {
			ans.pb(p[i - 1]);
			cur_dist = mt[p[i - 1]][p[i]];
		}
	}
	ans.pb(p.back());
	cout << len(ans) << endl;
	for (auto &x : ans) {
		cout << x + 1 << " ";
	}
	cout << endl;
}