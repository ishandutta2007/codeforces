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

int inline ksmii(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) mul(res, a);
		mul(a, a); b >>= 1;
	}
	return res;
}

int N;
int a[15];
int def[15][15];
int dp[1 << 15];

int main() {
	scanf("%d", &N);
	rep(i, N) scanf("%d", a + i);
	rep(i, N) rep(j, N) def[i][j] = Mul(a[i], ksmii(Add(a[i], a[j]), jt - 2));
	int ans = 0;
	rep(i, 1 << N) if (i) {
		int gals = 0;
		for (int j = i & (i - 1); j; j = i & (j - 1)) {
			int ngal = dp[j];
			rep(x, N) if ((j >> x) & 1) rep(y, N) if (!((j >> y) & 1) && ((i >> y) & 1)) mul(ngal, def[x][y]);
			add(gals, ngal); 
			if (i == (1 << N) - 1) add(ans, Mul(__builtin_popcount(j), ngal));
		}
		dp[i] = Sub(1, gals);
		if (i == (1 << N) - 1) add(ans, Mul(N, dp[i]));
	}
	printf("%d\n", ans);
	return 0;
}