#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;

const int jt = 1000000007;
void inline add(int &a, int b) { a += b - jt; a += (a >> 31) & jt; }
void inline sub(int &a, int b) { a -= b; a += (a >> 31) & jt; }
void inline mul(int &a, int b) { a = (ll)a * b % jt; }
int inline Add(int a, int b) { return a + b >= jt ? a + b - jt : a + b; }
int inline Sub(int a, int b) { return a - b < 0 ? a - b + jt : a - b; }
int inline Mul(int a, int b) { return (ll)a * b % jt; }

int inline ksmii(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) mul(res, a);
		mul(a, a); b >>= 1;
	}
	return res;
}

int N, Q;
int jc[3000005], fjc[3000005];
int dp[3000005][3];

int inline C(int a, int b) {
	return Mul(jc[a], Mul(fjc[b], fjc[a - b]));
}

int main() {
	scanf("%d%d", &N, &Q);
	jc[0] = 1; repi(i, N * 3) jc[i] = Mul(jc[i - 1], i);
	fjc[N * 3] = ksmii(jc[N * 3], jt - 2);
	for (int i = N * 3; i; --i) fjc[i - 1] = Mul(fjc[i], i);
	int mii3 = ksmii(3, jt - 2);
	dp[0][0] = dp[0][1] = dp[0][2] = N;
	repi(i, N * 3 - 1) {
		dp[i][0] = Mul(Sub(C(N * 3, i + 1), Add(Mul(2, dp[i - 1][0]), dp[i - 1][1])), mii3);
		dp[i][1] = Add(dp[i - 1][0], dp[i][0]);
		dp[i][2] = Add(dp[i - 1][1], dp[i][1]);
	}
	while (Q--) {
		int x; scanf("%d", &x);
		if (x == 3 * N) puts("1");
		else printf("%d\n", Add(dp[x][0], C(3 * N, x)));
	}
	return 0;
}