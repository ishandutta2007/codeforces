#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n, m;
		scanf("%d %d", &n, &m);
		char a[n][m], sol[m];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) scanf(" %c", &a[i][j]);
		}
		for (int i = 0; i < m; ++i) sol[i] = a[0][i];
		for (int i = 0; i < m; ++i) {
			for (char c = 'a'; c <= 'z'; ++c) {
				sol[i] = c;
				int delta = 1;
				for (int j = 0; j < n; ++j) {
					int cnt = 0;
					for (int k = 0; k < m; ++k) {
						if (sol[k] != a[j][k]) ++cnt;
					}
					delta = max(delta, cnt);
				}
				if (delta < 2) {
					for (int j = 0; j < m; ++j) printf("%c", sol[j]);
					printf("\n");
					goto hell;
				}
			}
			sol[i] = a[0][i];
		}
		printf("-1\n");
		hell:;
	}
	return 0;
}