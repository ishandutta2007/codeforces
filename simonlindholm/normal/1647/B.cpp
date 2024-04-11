#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define trav(a, x) for (auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N, M;
vector<vi> seen;

void run() {
	cin >> N >> M;
	vector<string> grid(N);
	rep(i,0,N) cin >> grid[i];
	seen.assign(N, vi(M, 0));
	rep(i,0,N) rep(j,0,M) if (!seen[i][j] && grid[i][j] == '1') {
		vector<pii> st = {{i,j}};
		int co = 0;
		int mini = INT_MAX, minj = INT_MAX;
		int maxi = INT_MIN, maxj = INT_MIN;
		while (!st.empty()) {
			pii pa = st.back();
			st.pop_back();
			if (pa.first < 0 || pa.second < 0 || pa.first >= N || pa.second >= M) continue;
			if (seen[pa.first][pa.second]++) continue;
			if (grid[pa.first][pa.second] != '1') continue;
			co++;
			mini = min(mini, pa.first);
			maxi = max(maxi, pa.first);
			minj = min(minj, pa.second);
			maxj = max(maxj, pa.second);
			st.push_back({pa.first-1, pa.second});
			st.push_back({pa.first+1, pa.second});
			st.push_back({pa.first, pa.second+1});
			st.push_back({pa.first, pa.second-1});
		}
		if (co != (maxi - mini + 1) * (maxj - minj + 1)) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	rep(i,0,N) run();
}