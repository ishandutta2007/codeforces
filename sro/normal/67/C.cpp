#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int ti, td, tr, te;
int NN;
char s[5005], t[5005];
int dp[5005][5005];

int val[27][5005];
int pre[5005][27], nxt[5005][27];
int lstpos[27];

int main() {
	scanf("%d%d%d%d", &ti, &td, &tr, &te);
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	int N = strlen(s + 1), M = strlen(t + 1);
	memset(lstpos, 0, sizeof(lstpos));
	repi(i, M) {
		rep(j, 26) pre[i][j] = lstpos[j];
		lstpos[t[i] - 'a'] = i;
	}
	rep(j, 26) lstpos[j] = M + 1;
	for (int i = M; i; --i) {
		rep(j, 26) nxt[i][j] = lstpos[j];
		lstpos[t[i] - 'a'] = i;
	}
	NN = max(N, M);
	memset(dp, Inf, sizeof(dp));
	dp[0][0] = 0;
	memset(val, Inf, sizeof(val));
	rep(i, N + 1) {
		rep(j, M + 1) {
			if (i && j) {
				val[s[i] - 'a'][j] = min(val[s[i] - 'a'][j], val[s[i] - 'a'][pre[j][t[j] - 'a']]);
				dp[i][j] = min(dp[i][j], val[s[i] - 'a'][j] + td * i + ti * j + te);
			}
			int c1 = s[i + 1], c2 = t[j + 1];
			if (i < N && j < M) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + (c1 == c2 ? 0 : tr));
			if (i < N) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + td);
			if (j < M) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + ti);
		}
		if (i) rep(j, M + 1) {
			int c1 = s[i], c2 = t[j + 1];
			if (i < N && j < M - 1) {
				val[c2 - 'a'][nxt[j + 1][c1 - 'a']] = min(val[c2 - 'a'][nxt[j + 1][c1 - 'a']], dp[i - 1][j] - (i + 1) * td - (j + 2) * ti);
			}
		}
	}
	printf("%d\n", dp[N][M]);
	return 0;
}