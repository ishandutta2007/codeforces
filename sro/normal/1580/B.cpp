#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int jt;
void inline add(int &a, int b) { a += b - jt; a += (a >> 31) & jt; }
void inline sub(int &a, int b) { a -= b; a += (a >> 31) & jt; }
void inline mul(int &a, int b) { a = 1ll * a * b % jt; }
int inline Add(int a, int b) { return a + b >= jt ? a + b - jt : a + b; }
int inline Sub(int a, int b) { return a - b < 0 ? a - b + jt : a - b; }
int inline Mul(int a, int b) { return 1ll * a * b % jt; }

int N, M, K;
int dp[105][105][105];
int C[105][105], jc[105];

int main() {
	scanf("%d%d%d%d", &N, &M, &K, &jt);
	for (int i = 0; i <= N; ++i) C[i][0] = 1;
	for (int i = 1; i <= N; ++i) for (int j = 1; j <= i; ++j) C[i][j] = Add(C[i - 1][j], C[i - 1][j - 1]);
	jc[0] = 1;
	for (int i = 1; i <= N; ++i) jc[i] = Mul(jc[i - 1], i);
	for (int j = 0; j <= M; ++j) dp[0][j][0] = dp[1][j][0] = 1;
	dp[1][0][1] = 1; dp[1][0][0] = 0;
	for (int i = 2; i <= N; ++i) {
		dp[i][0][1] = jc[i];
		for (int j = 1; j < min(M, i + 3); ++j) {
			int mxk = min(K, j <= 7 ? (1 << j) : 114);
			for (int ni = 0; ni < i; ++ni) for (int nk = 0; nk <= mxk; ++nk) if (dp[ni][j - 1][nk]) {
				int mxnk = i - ni + 3 > j ? mxk : nk;
				for (int k = nk; k <= mxnk; ++k) if (k) {
					add(dp[i][j][k], Mul(Mul(dp[ni][j - 1][nk], dp[i - ni - 1][j - 1][k - nk]), C[i - 1][ni]));
				}
			}
		}
		for (int j = 1; j < M; ++j) {
			for (int ni = 0; ni < i; ++ni) if (dp[ni][j - 1][0]) {
				add(dp[i][j][0], Mul(Mul(dp[ni][j - 1][0], dp[i - ni - 1][j - 1][0]), C[i - 1][ni]));
			}
		}
	}
	printf("%d\n", dp[N][M - 1][K]);
	return 0;
}
//