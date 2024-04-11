#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1000000
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	vector<int> perm(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> perm[i];
	}
	vector<string> adjmat(n, "");
	for (int i = 0; i < n; ++i) {
		cin >> adjmat[i];
	}
	vector<int> ans(n, -1);
	for (int i = 0; i < n; ++i) {
		if (ans[i] == -1) {
			//cout << "starting new group at " << i << endl;
			vector<int> indicesToCheck;
			ans[i] = INF;
			queue<int> q;
			q.push(i);
			while (!q.empty()) {
				int cur = q.front(); q.pop();
				//cout << "in bfs: visiting " << cur << endl;
				indicesToCheck.push_back(cur);
				for (int pnei = 0; pnei < n; ++pnei) {
					//cout << "candidate dest " << pnei << ": " << (adjmat[cur][pnei] == '1') << (ans[pnei] == -1) << endl; 
					if (adjmat[cur][pnei] == '1' && ans[pnei] == -1) {
						ans[pnei] = INF;
						q.push(pnei);
					}
				}
			}
			int k = indicesToCheck.size();
			vector<int> valuesToPut(k, 0);
			for (int j = 0; j < k; ++j) {
				//cout << "element of current group is " << indicesToCheck[j] << endl;
				valuesToPut[j] = perm[indicesToCheck[j]];
			}
			sort(valuesToPut.begin(), valuesToPut.end());
			sort(indicesToCheck.begin(), indicesToCheck.end());
			for (int j = 0; j < k; ++j) {
				ans[indicesToCheck[j]] = valuesToPut[j];
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << (i == 0 ? "" : " ") << ans[i];
	}
	cout << endl;
	return 0;
}