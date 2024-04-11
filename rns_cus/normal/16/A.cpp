#include <bits/stdc++.h>
using namespace std;
#define N 1010

int n, m;
char s[N][N];

bool ok() {
	for (int i = 0; i < n; i ++) {
		char col = s[i][0];
		for (int j = 1; j < m; j ++) {
			if (s[i][j] != col) return 0;
		}
		if (i && s[i][0] == s[i-1][0]) return 0;
	}
	return 1;
}

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i ++) {
		scanf("%s", s[i]);
	}
	if (ok()) puts("YES");
	else puts("NO");
	return 0;
}
//16-a