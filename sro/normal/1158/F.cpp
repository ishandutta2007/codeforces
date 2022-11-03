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

const int jt = 998244353, maxn = 4096;

struct Segtree {
	int dt[maxn << 1];
	void init() { memset(dt, 0, sizeof(dt)); }
	void inline mul(int a) {
		++(dt[a += maxn] *= 2) %= jt;
		while (a >>= 1) dt[a] = 1ll * dt[a << 1] * dt[a << 1 | 1] % jt;
	}
	int inline get(int l, int r) {
		int ans = 1;
		for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ans = 1ll * ans * dt[l++] % jt;
			if (r & 1) ans = 1ll * ans * dt[--r] % jt;
		}
		return ans;
	}
} seg;

int n, c;
int a[3005];
int dp[2][3005][1 << 10], lgl[2][3005][1 << 10];
int sti[3005][3005], f[3005][3005], mii[3005], res[3005];

void inline add(int &a, int x) {
	a += x - jt; a += (a >> 31) & jt;
}

void solve() {
	cont(i, n) --a[i];
	dp[0][0][0] = 1; lgl[0][0][0] = 0;
	int now = 1, lst = 0;
	cont(i, n) {
		loop(j, i / c + 1) loop(k, 1 << c) if (lgl[lst][j][k] == i - 1) {
			if (lgl[now][j][k] != i) {
				lgl[now][j][k] = i;
				dp[now][j][k] = 0;
			}
			int nk = k | (1 << a[i]), ad = 0;
			if (nk == (1 << c) - 1) nk = 0, ad = 1;
			if (lgl[now][j + ad][nk] != i) {
				lgl[now][j + ad][nk] = i;
				dp[now][j + ad][nk] = 0;
			}
			add(dp[now][j][k], dp[lst][j][k]);
			add(dp[now][j + ad][nk], dp[lst][j][k]);
		}
		swap(now, lst);
	}
	loop(i, n + 1) {
		int ans = 0;
		loop(j, 1 << c) add(ans, dp[lst][i][j]);
		if (!i) add(ans, jt - 1);
		printf("%d ", ans);
	}
}

int main() {
	scanf("%d%d", &n, &c);
	mii[0] = 1;
	cont(i, n) mii[i] = 2 * mii[i - 1] % jt;
	cont(i, n) scanf("%d", a + i);
	if (c <= 10) return solve(), 0;
	cont(i, n) {
		seg.init();
		range(j, i, 1, -1) {
			if (j == i || a[j] != a[i]) {
				seg.mul(a[j]);
				sti[j][i] = seg.get(1, c);
			} else {
				sti[j][i] = sti[j + 1][i];
			}
		}
	}
	f[0][0] = 1;
	loop(i, n) loop(j, i / c + 1) if (f[i][j]) {
		circ(k, i + 1, n) {
			add(f[k][j + 1], 1ll * f[i][j] * sti[i + 1][k] % jt);
		}
	}
	loop(i, n + 1) {
		int ans = 0;
		loop(j, n + 1) add(ans, 1ll * f[j][i] * mii[n - j] % jt);
		if (!i) add(ans, jt - 1);
		res[i] = ans;
	}
	loop(i, n + 1) add(res[i], jt - res[i + 1]);
	loop(i, n + 1) printf("%d ", res[i]);
	return 0;
}