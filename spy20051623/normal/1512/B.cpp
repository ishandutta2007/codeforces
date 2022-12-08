#include <bits/stdc++.h>

using namespace std;

char mp[405][405];

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, cnt;
	pair<int, int> p[10];
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		cnt = 0;
		for (int i = 0; i < n; ++i) {
			getchar();
			for (int j = 0; j < n; ++j) {
				mp[i][j] = getchar();
				if (mp[i][j] == '*')
					p[cnt++] = make_pair(i, j);
			}
		}
		if (p[0].first != p[1].first && p[0].second != p[1].second) {
			mp[p[0].first][p[1].second] = '*';
			mp[p[1].first][p[0].second] = '*';
		} else if (p[0].first == p[1].first) {
			if (p[0].first == 0) {
				mp[1][p[0].second] = '*';
				mp[1][p[1].second] = '*';
			} else {
				mp[0][p[0].second] = '*';
				mp[0][p[1].second] = '*';
			}
		} else {
			if (p[0].second == 0) {
				mp[p[0].first][1] = '*';
				mp[p[1].first][1] = '*';
			} else {
				mp[p[0].first][0] = '*';
				mp[p[1].first][0] = '*';
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				printf("%c", mp[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}