#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;
int a[N], s[N];

int main() {
//	freopen("in.txt", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	vector<vector<char>> g(n, vector<char>(m));
	for (int i = 0; i < n; ++i) {
		getchar();
		for (int j = 0; j < m; ++j) {
			g[i][j] = getchar();
			if (g[i][j] != '.' && g[i][j] != 'X') exit(-1);
		}
	}
	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			if (g[j - 1][i] == 'X' && g[j][i - 1] == 'X') {
				a[i] = 1;
				break;
			}
		}
	}
	for (int i = 1; i < m; ++i) {
		s[i] = s[i - 1] + a[i];
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		--l, --r;
		if (s[r] - s[l]) puts("NO");
		else puts("YES");
	}
	return 0;
}