#include <bits/stdc++.h>
using namespace std;

#define N 125005

char S[N], T[N];

const int K = 6;

bitset <N> b[K][K], s[K];

bool vis[K];

int q[K+2];

int main() {
	gets(S), gets(T);
	int n = strlen(S);
	int m = strlen(T);
	for (int i = 0; i < n; i ++) s[S[i]-'a'][i] = 1;
	for (int i = 0; i < m; i ++) {
		int h = T[i] - 'a';
		for (int k = 0; k < K; k ++) {
			if (h == k) continue;
			b[h][k] |= s[k];
		}
		for (int k = 0; k < K; k ++) s[k] >>= 1;
	}
	for (int k = 0; k <= n - m; k ++) {
		memset(vis, 0, sizeof vis);
		int ans = 0;
		for (int i = 0; i < K; i ++) if (!vis[i]) {
			int e = 0;
			q[++e] = i;
			for (int f = 1, x; f <= e; f ++) {
				x = q[f];
				vis[x] = 1;
				for (int j = 0; j < K; j ++) if (!vis[j]) {
					if (b[x][j][k] || b[j][x][k]) {
						q[++e] = j;
						vis[j] = 1;
					}
				}
			}
			ans ++;
		}
		printf("%d ", 6 - ans);
	}
	puts("");


	return 0;
}