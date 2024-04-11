#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

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

int dp[2][305][305][305];
int n;
int d[305];
int jc[305], mii[305];
int C2[305];

int main() {
    scanf("%d", &n);
    cont(i, n) {
        scanf("%d", d + i);
        if (i > 1) --d[i];
    }
    cont(i, n) C2[i] = i * (i - 1) / 2;
    jc[0] = 1;
    cont(i, n) jc[i] = Mul(jc[i - 1], i);
    mii[0] = 1; mii[1] = (jt + 1) / 2;
    circ(i, 2, n) mii[i] = Mul(mii[i - 1], mii[1]);
    dp[0][d[1]][0][0] = 1;
    int now = 1, lst = 0;
    circ(i, 2, n) {
        loop(k, n + 1) loop(l, n + 1) if (k + l * 2 <= n) {
            add(dp[lst][k + l * 2][0][0], Mul(dp[lst][0][k][l], Mul(jc[k + l * 2], mii[l])));
        }
        loop(j, n - i + 2) loop(k, n - j + 4) loop(l, ((n - k) >> 1) + 2) dp[now][j][k][l] = 0;
        cont(j, n - i + 1) loop(k, n - j + 2) loop(l, ((n - k) >> 1) + 1) if (dp[lst][j][k][l]) {
            // select none
            if (d[i] == 1) {
                if (k >= 1) add(dp[now][j - 1][k - 1][l], Mul(k, dp[lst][j][k][l]));
                if (l >= 1) add(dp[now][j - 1][k + 1][l - 1], Mul(l, dp[lst][j][k][l]));
            }
            else if (d[i] == 2) {
                if (k >= 2) add(dp[now][j - 1][k - 2][l], Mul(C2[k], dp[lst][j][k][l]));
                if (k >= 1 && l >= 1) add(dp[now][j - 1][k][l - 1], Mul(Mul(k, l), dp[lst][j][k][l]));
                if (l >= 2) add(dp[now][j - 1][k + 2][l - 2], Mul(C2[l], dp[lst][j][k][l]));
            }
            // select one
            if (d[i] == 1) {
                add(dp[now][j - 1][k + 1][l], dp[lst][j][k][l]);
            }
            else if (d[i] == 2) {
                if (k >= 1) add(dp[now][j - 1][k][l], Mul(k, dp[lst][j][k][l]));
                if (l >= 1) add(dp[now][j - 1][k + 2][l - 1], Mul(l, dp[lst][j][k][l]));
            }
            // select two
            if (d[i] == 2) {
                add(dp[now][j - 1][k][l + 1], dp[lst][j][k][l]);
            }
        }
        swap(now, lst);
    }
    printf("%d\n", dp[lst][0][0][0]);
    return 0;
}
/*

5
2 3 3 2 2

*/