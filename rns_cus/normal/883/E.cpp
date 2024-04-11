#include <bits/stdc++.h>
using namespace std;

#define N 55
#define M 1010

int n, m;
char s[N], t[M][N];

bool vis[M];
int aa[555], bb[555];
int val[M];

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d\n", &n);
	gets(s);
	scanf("%d\n", &m);
	for (int i = 1; i <= m; i ++) gets(t[i]), vis[i] = 1;
	for (int i = 0; i < n; i ++) if (s[i] != '*') aa[s[i]] ++;
	for (int i = 1; i <= m; i ++) {
		memset(bb, 0, sizeof bb);
		for (int j = 0; j < n; j ++) if (s[j] != '*' && s[j] != t[i][j]) {
			vis[i] = 0;
			break;
		}
		if (vis[i]) {
			for (int j = 0; j < n; j ++) bb[t[i][j]] ++;
			for (char c = 'a'; c <= 'z'; c ++) if (aa[c] && aa[c] != bb[c]) {
				vis[i] = 0;
				break;
			}
		}
	}

	for (int i = 1; i <= m; i ++) if (vis[i]) {
		val[i] = 0;
		for (int j = 0; j < n; j ++) if (s[j] == '*') {
			val[i] |= 1 << ((int)(t[i][j] - 'a'));
		}
	}
	int ans = (1 << 26) - 1;
	for (int i = 1; i <= m; i ++) if (vis[i]) ans &= val[i];
	int tot = 0;
	for (int i = 0; i < 26; i ++) if (ans & (1 << i)) tot ++;
	printf("%d\n", tot);

	return 0;
}