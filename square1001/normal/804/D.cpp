#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int curdiam, curopt;
void dfs(int pos, int pre, int depth, int cnt, vector<vector<int> >& G, vector<int>& col, vector<int>& h) {
	col[pos] = cnt;
	h[pos] = max(h[pos], depth);
	if (curdiam < depth) {
		curdiam = depth;
		curopt = pos;
	}
	for (int i : G[pos]) {
		if (i == pre) continue;
		dfs(i, pos, depth + 1, cnt, G, col, h);
	}
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M, Q;
	cin >> N >> M >> Q;
	vector<vector<int> > G(N);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b; --a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int> col(N, -1), h(N), diam;
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		if (col[i] == -1) {
			curdiam = -1;
			dfs(i, -1, 0, cnt, G, col, h);
			curdiam = -1;
			dfs(curopt, -1, 0, cnt, G, col, h);
			curdiam = -1;
			dfs(curopt, -1, 0, cnt, G, col, h);
			++cnt;
			diam.push_back(curdiam);
		}
	}
	vector<vector<int> > hist(cnt);
	for (int i = 0; i < N; ++i) {
		hist[col[i]].push_back(h[i]);
	}
	for (int i = 0; i < cnt; ++i) {
		sort(hist[i].begin(), hist[i].end());
	}
	vector<vector<long long> > sum(cnt);
	for (int i = 0; i < cnt; ++i) {
		sum[i].resize(hist[i].size() + 1);
		for (int j = hist[i].size() - 1; j >= 0; --j) {
			sum[i][j] = sum[i][j + 1] + hist[i][j];
		}
	}
	cout.precision(15);
	map<pair<int, int>, double> dp;
	for (int i = 0; i < Q; ++i) {
		int a, b;
		cin >> a >> b; --a, --b;
		a = col[a], b = col[b];
		if (hist[a].size() > hist[b].size()) swap(a, b);
		if (a == b) {
			cout << -1 << '\n';
		}
		else if (dp.find(make_pair(a, b)) != dp.end()) {
			cout << dp[make_pair(a, b)] << '\n';
		}
		else {
			int mindiam = max(diam[a], diam[b]);
			double ans = 0;
			for (int j : hist[a]) {
				int ptr = lower_bound(hist[b].begin(), hist[b].end(), mindiam - j) - hist[b].begin();
				ans += 1LL * ptr * mindiam + sum[b][ptr] + 1LL * (j + 1) * (hist[b].size() - ptr);
			}
			ans /= hist[a].size();
			ans /= hist[b].size();
			cout << ans << '\n';
			dp[make_pair(a, b)] = ans;
		}
	}
	return 0;
}