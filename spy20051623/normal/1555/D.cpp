#include <bits/stdc++.h>

using namespace std;

const char str[6][4] = {"abc", "bca", "cab", "cba", "bac", "acb"};
char s[200005];
int ans[200005][6];

int main() {
//	freopen("in.txt", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 6; ++j) {
			ans[i][j] = ans[i - 1][j] + (s[i] != str[j][i % 3]);
		}
	}
	while (m--) {
		int l, r;
		scanf("%d%d", &l, &r);
		int Ans = 1e9;
		for (int i = 0; i < 6; ++i) {
			Ans = min(Ans, ans[r][i] - ans[l - 1][i]);
		}
		printf("%d\n", Ans);
	}
	return 0;
}