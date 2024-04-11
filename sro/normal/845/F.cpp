#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

const int jt = 1000000007;
void inline add(int &a, int b) { a += b - jt; a += (a >> 31) & jt; }
void inline sub(int &a, int b) { a -= b; a += (a >> 31) & jt; }
void inline mul(int &a, int b) { a = 1ll * a * b % jt; }
int inline Add(int a, int b) { return a + b >= jt ? a + b - jt : a + b; }
int inline Sub(int a, int b) { return a - b < 0 ? a - b + jt : a - b; }
int inline Mul(int a, int b) { return 1ll * a * b % jt; }

int N, M;
char s[255][255], tmp[255][255];
int dp[255][1 << 15][2][2];

int main() {
	scanf("%d%d", &N, &M);
	rep(i, N) scanf("%s", s[i]);
	if (N < M) {
		rep(i, N) rep(j, M) tmp[j][i] = s[i][j];
		swap(N, M); memcpy(s, tmp, sizeof(s));
	}
	int fulm = (1 << M) - 1;
	dp[0][0][0][0] = 1;
	rep(i, N * M) rep(msk, 1 << M) rep(hs, 2) rep(hv, 2) {
		int x = i / M, y = i % M;
		if (s[x][y] == 'x') {
			add(dp[i + 1][(msk << 1) & fulm][0][hv], dp[i][msk][hs][hv]);
			continue;
		}
		bool is = (msk >> (M - 1)) & 1;
		add(dp[i + 1][(msk << 1 | 1) & fulm][y == M - 1 ? 0 : 1][hv], dp[i][msk][hs][hv]);
		if (is || hs || !hv) {
			add(dp[i + 1][(msk << 1 | is) & fulm][y == M - 1 ? 0 : hs][!is && !hs ? 1 : hv], dp[i][msk][hs][hv]);
		}
	}
	int ans = 0;
	rep(msk, 1 << M) rep(hv, 2) add(ans, dp[N * M][msk][0][hv]);
	printf("%d\n", ans);
	return 0;
}