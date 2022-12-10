#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	bool tak[n+1][n+1];
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			tak[i][j] = false;
			pq.push(pii(i, j));
		}
	}
	if (k > 0) {
		tak[1][1] = true;
		k--;
		if (k%2 == 1 && n > 1) {
			tak[2][2] = true;
			k--;
		}
		while (k > 0&& pq.size() > 0) {
			pii cur = pq.top(); pq.pop();
			if (tak[cur.first][cur.second]) continue;
			if (cur.first == cur.second) {
				if (cur.first == n) continue;
				tak[cur.first][cur.second] = true;
				tak[cur.first+1][cur.second+1] = true;
				k -= 2;
			}
			else {
				k-=2;
				tak[cur.first][cur.second] = true;
				tak[cur.second][cur.first] = true;
			}
		}
		
	}
	if (k > 0) {
		cout << -1 << endl;
	}
	else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (tak[i][j]) cout << 1 << " ";
				else cout << 0 << " ";
			}
			cout << endl;
		}
	}
	cin >> n;
}