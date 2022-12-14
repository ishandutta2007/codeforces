#include <bits/stdc++.h>
using namespace std;
#define M 510
int n, K, TT;
char s[10][M];
int vis[10][M], flag[10][M];

int main() {
//	freopen("B.in", "r", stdin);
	int T;
	for (scanf("%d", &T); T--; ) {
		scanf("%d %d", &n, &K); ++TT;
		for (int i = 0; i < 3; i++) scanf("%s", s[i]);
		for (int i = 0; i < 3; i++) {
			if (s[i][0] == 's') vis[i][0] = TT;
			for (int j = 0; j < n; j++) if (s[i][j] != '.') flag[i][j] = TT;
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < 3; j++) {
				if (vis[j][i] == TT) {
					if (flag[j][3*i+1] == TT) continue;
					int st = max(0, j - 1), en = min(2, j + 1);
					for (int k = st; k <= en; k++) {
						if (flag[k][3*i+1] != TT && flag[k][3*i+3] != TT) vis[k][i+1] = TT;
					}
				}
			}
		}
		bool bf = 0;
		for (int j = 0; j < 3; j++) {
			if (vis[j][n-1] == TT) {bf = 1; puts("YES"); break;}
		}
		if (!bf) puts("NO");
	}
}