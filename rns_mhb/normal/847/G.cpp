#include <bits/stdc++.h>
using namespace std;

#define N 1010

int n;
char s[N][10];

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d\n", &n);
	for (int i = 1; i <= n; i ++) gets(s[i]);
	int ans = 0;
	for (int j = 0; j < 7; j ++) {
		int now = 0;
		for (int i = 1; i <= n; i ++) if (s[i][j] == '1') now ++;
		ans = max(ans, now);
	}
	printf("%d\n", ans);
	return 0;
}