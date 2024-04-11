#include <queue>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M; vector<int> A(3);
	cin >> N >> M >> A[0] >> A[1] >> A[2];
	vector<vector<int> > G(N);
	for (int i = 0; i < M; ++i) {
		int x, y;
		cin >> x >> y; --x, --y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	vector<vector<int> > gs;
	bool ok = true;
	vector<int> col(N, -1);
	vector<int> comp(N, -1);
	for (int i = 0; i < N; ++i) {
		if (col[i] != -1) continue;
		queue<int> que;
		que.push(i);
		col[i] = 0;
		vector<int> subgs;
		while (!que.empty()) {
			int u = que.front();
			que.pop();
			subgs.push_back(u);
			comp[u] = gs.size();
			for (int j : G[u]) {
				if (col[j] == -1) {
					col[j] = col[u] ^ 1;
					que.push(j);
				}
			}
		}
		gs.push_back(subgs);
	}
	for (int i = 0; i < N; ++i) {
		for (int j : G[i]) {
			if (col[i] == col[j]) {
				ok = false;
			}
		}
	}
	if (!ok) {
		cout << "NO" << endl;
	}
	else {
		int K = gs.size();
		vector<int> a(K), b(K);
		for (int i = 0; i < K; ++i) {
			for (int j : gs[i]) {
				if (col[j] == 0) ++a[i];
				else ++b[i];
			}
		}
		vector<vector<bool> > dp(K + 1, vector<bool>(A[1] + 1));
		dp[0][0] = true;
		for (int i = 0; i < K; ++i) {
			for (int j = 0; j <= A[1]; ++j) {
				if (j >= a[i] && dp[i][j - a[i]]) dp[i + 1][j] = true;
				if (j >= b[i] && dp[i][j - b[i]]) dp[i + 1][j] = true;
			}
		}
		if (!dp[K][A[1]]) {
			cout << "NO" << endl;
		}
		else {
			vector<int> sel(K, -1);
			int pos = A[1];
			for (int i = K - 1; i >= 0; --i) {
				if (pos >= a[i] && dp[i][pos - a[i]]) {
					pos -= a[i];
					sel[i] = 0;
				}
				else {
					pos -= b[i];
					sel[i] = 1;
				}
			}
			vector<int> ans(N);
			for (int i = 0; i < N; ++i) {
				if ((sel[comp[i]] ^ col[i]) == 0) {
					ans[i] = 2; --A[2];
				}
				else {
					if (A[0] > 0) ans[i] = 1, --A[0];
					else ans[i] = 3, --A[2];
				}
			}
			cout << "YES" << endl;
			for (int i = 0; i < N; ++i) {
				cout << ans[i];
			}
			cout << endl;
		}
	}
	return 0;
}