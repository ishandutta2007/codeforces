#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

const int jt = 998244353;
void inline add(int &a, int b) { a += b - jt; a += (a >> 31) & jt; }
void inline sub(int &a, int b) { a -= b; a += (a >> 31) & jt; }
void inline mul(int &a, int b) { a = 1ll * a * b % jt; }
int inline Add(int a, int b) { return a + b >= jt ? a + b - jt : a + b; }
int inline Sub(int a, int b) { return a - b < 0 ? a - b + jt : a - b; }
int inline Mul(int a, int b) { return 1ll * a * b % jt; }

int N, M;
int x[5], y[5];
int dp[32][22][22][22][22][2][2];
int u1s[32], v1s[32], u2s[32], v2s[32];

int main() {
	scanf("%d%d", &N, &M);
	rep(i, N) scanf("%d%d", x + i, y + i);
	rep(msk, 1 << N) {
		rep(j, N) if ((msk >> j) & 1) {
			if (x[j] > 0) u1s[msk] -= x[j];
			else v1s[msk] += x[j];
			if (y[j] > 0) u2s[msk] -= y[j];
			else v2s[msk] += y[j];
		}
	}
	dp[31][0][0][0][0][0][0] = 1;
	for (int i = 31; i; --i) {
		rep(u1, 20) rep(u2, 20) rep(v1, 20) rep(v2, 20) rep(s1, 2) rep(s2, 2) {
			if (!dp[i][u1][u2][v1][v2][s1][s2]) continue;
			int val = dp[i][u1][u2][v1][v2][s1][s2];
			int umx = s1 ? 1 : ((M >> (i - 1)) & 1), vmx = s2 ? 1 : ((M >> (i - 1)) & 1);
			rep(n1, umx + 1) rep(n2, vmx + 1) {
				int nu1 = u1 * 2 + n1, nu2 = u2 * 2 + n2;
				int nv1 = v1 * 2 + n1, nv2 = v2 * 2 + n2;
				rep(msk, 1 << N) {
					int mu1 = nu1 + u1s[msk], mu2 = nu2 + u2s[msk], mv1 = nv1 + v1s[msk], mv2 = nv2 + v2s[msk];
					if (mu1 < 0 || mu2 < 0 || mv1 < 0 || mv2 < 0) continue;
					if (mu1 >= 20 || mu2 >= 20 || mv1 >= 20 || mv2 >= 20) continue;
					add(dp[i - 1][mu1][mu2][mv1][mv2][s1 | (n1 < umx)][s2 | (n2 < vmx)], val);
				}
			}
		}
	}
	int sm = 0;
	rep(s1, 2) rep(s2, 2) add(sm, dp[0][0][0][0][0][s1][s2]);
	sm = Sub(sm, 1);
	printf("%d\n", sm);
	return 0;
}