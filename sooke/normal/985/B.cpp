#include <cstdio>

#define Maxn 2001

inline int read() {
	char c = getchar();
	while (c < '0' || c > '9') {
		c = getchar();
	}
	return c ^ 48;
}

int n, m, a[Maxn][Maxn], cnt[Maxn];

inline bool check(int d) {
	for (int i = 1; i <= m; i++) {
		if (a[d][i] == 1 && cnt[i] == 1) {
			return false;
		}
	}
	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			a[i][j] = read();
			cnt[j] += a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (check(i)) {
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}

// By Sooke.
// CF985B Switches and Lamps.