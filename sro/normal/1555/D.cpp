#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;

int N, M;
char s[200005];
int dis[6][200005];

int main() {
	scanf("%d%d", &N, &M);
	scanf("%s", s + 1);
	repi(i, N) {
		rep(j, 6) {
			int ch;
			if (j < 3) ch = (i + j) % 3 + 'a';
			else ch = (j + N - i) % 3 + 'a';
			dis[j][i] = ch != s[i];
		}
	}
	rep(i, 6) repi(j, N) dis[i][j] += dis[i][j - 1];
	while (M--) {
		int l, r; scanf("%d%d", &l, &r);
		int res = 0x3f3f3f3f;
		rep(i, 6) res = min(res, dis[i][r] - dis[i][l - 1]);
		printf("%d\n", res);
	}
	return 0;
}