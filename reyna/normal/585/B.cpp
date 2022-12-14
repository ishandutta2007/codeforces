//In the name of God
// Break through! I screamed forth from my soul!

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> query;

const int N = 200 + 49;
string s[3];
int train[3][N][N], h, t, mark[3][N];
query q[N * N * 3];


int32_t main() {
	ios_base::sync_with_stdio(0);
	int tc; cin >> tc;
	while (tc--) {
		memset(train, 0, sizeof train);
		memset(mark, 0, sizeof mark);
		t = 0, h = 0;
		int n, k; cin >> n >> k;
		for (int i = 0; i < 3; i++) {
			cin >> s[i];
			for (int j = 0; j < n; j++) {
				if (s[i][j] != '.' && s[i][j] != 's')
					train[i][j][0] = 1;
				if (s[i][j]	== 's') {
					q[t++] = {i, j};
					
				}
			}
			for (int ti = 1; ti < n; ti++)
				for (int j = 2; j < n; j++)
					if (train[i][j][ti - 1])
						train[i][j - 2][ti] = 1;
		}
		bool flag = 0;
		while (h != t) {
			query cur = q[h++];
			int j = cur.first, i = cur.second;
			if (i == n - 1) {
				cout << "YES\n";
				flag = 1;
				break;	
			}
			for (int k = -1; k <= 1; k++) {
				int x = i + 1, y = j + k;
				if (y == 3 || y == -1) continue;
				if (!mark[y][x] && !train[y][x][i] && !train[y][x][x] && !train[j][x][i]) {
					mark[y][x] = 1;
					q[t++] = {y, x};
				} 
			}
		}
		if (flag) continue;
		cout << "NO\n";
	}
}