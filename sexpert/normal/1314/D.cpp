#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 85;
vector<ii> best[MAXN][MAXN];
int dis[MAXN][MAXN], used[MAXN];
int n, k;
vector<int> trip;
int ans = INT_MAX;

void solve(int step, int s) {
	trip.push_back(s);
	used[s]++;
	if(step < k/2) {
		for(int i = 0; i < n; i++) {
			solve(step + 1, i);
		}
	}
	else {
		int res = 0;
		bool good = true;
		for(int i = 0; i + 1 < k/2; i++) {
			bool found = false;
			for(auto p : best[trip[i]][trip[i + 1]]) {
				if(used[p.second] == 0) {
					res += p.first;
					found = true;
					break;
				}
			}
			if(!found)
				good = false;
		}
		bool found = false;
		for(auto p : best[trip[k/2 - 1]][trip[0]]) {
			if(used[p.second] == 0) {
				res += p.first;
				found = true;
				break;
			}
		}
		if(!found)
			good = false;
		if(good)
			ans = min(ans, res);
	}
	used[s]--;
	trip.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> dis[i][j];
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int t = 0; t < n; t++) {
				if(t == i || t == j)
					continue;
				best[i][j].push_back({dis[i][t] + dis[t][j], t});
			}
			sort(best[i][j].begin(), best[i][j].end());
			if(best[i][j].size() > 7)
				best[i][j].resize(7);
		}
	}
	solve(1, 0);
	cout << ans << '\n';
}