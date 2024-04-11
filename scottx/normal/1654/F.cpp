#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using LL = long long;
const int N = (1 << 18) + 5, P = 998244853, B = 31;
int n, pw[N];
char s[N];
vector<int> key[N << 2];
void bud(int u, int l, int r, int bit) {
	key[u].resize(r - l + 1);
	if (l == r) {
		key[u][0] = s[l] - 'a' + 1;
		return;
	}
	int mid = (l + r) >> 1;
	bud(u << 1, l, mid, bit - 1), bud(u << 1 | 1, mid + 1, r, bit - 1);
	rep(i, 0, r - l) {
		if (i >> (bit - 1) & 1) {
			key[u][i] = (LL(key[u << 1 | 1][i & (~(1 << (bit - 1)))]) * pw[r - mid] + key[u << 1][i & (~(1 << (bit - 1)))]) % P;
		} else {
			key[u][i] = (LL(key[u << 1][i & (~(1 << (bit - 1)))]) * pw[mid - l + 1] + key[u << 1 | 1][i & (~(1 << (bit - 1)))]) % P;
		}
	}
}
int cmp(int u1, int l1, int r1, int mask1, int u2, int l2, int r2, int mask2, int bit) {
	if (l1 == r1) {
		return s[l1] != s[l2] ? (s[l1] < s[l2] ? -1 : 1) : 0;
	}
	if (key[u1][mask1] == key[u2][mask2]) {
		return 0;
	}
	int u1_, l1_, r1_, u2_, l2_, r2_;

	if (mask1 >> (bit - 1) & 1) {
		u1_ = u1 << 1 | 1;
		l1_ = ((l1 + r1) >> 1) + 1;
		r1_ = r1;
	} else {
		u1_ = u1 << 1;
		l1_ = l1;
		r1_ = (l1 + r1) >> 1;
	}

	if (mask2 >> (bit - 1) & 1) {
		u2_ = u2 << 1 | 1;
		l2_ = ((l2 + r2) >> 1) + 1;
		r2_ = r2;
	} else {
		u2_ = u2 << 1;
		l2_ = l2;
		r2_ = (l2 + r2) >> 1;
	}


	int t = cmp(u1_, l1_, r1_, mask1 & (~(1 << (bit - 1))), u2_, l2_, r2_, mask2 & (~(1 << (bit - 1))), bit - 1);
	if (t != 0) return t;

	if (~mask1 >> (bit - 1) & 1) {
		u1_ = u1 << 1 | 1;
		l1_ = ((l1 + r1) >> 1) + 1;
		r1_ = r1;
	} else {
		u1_ = u1 << 1;
		l1_ = l1;
		r1_ = (l1 + r1) >> 1;
	}

	if (~mask2 >> (bit - 1) & 1) {
		u2_ = u2 << 1 | 1;
		l2_ = ((l2 + r2) >> 1) + 1;
		r2_ = r2;
	} else {
		u2_ = u2 << 1;
		l2_ = l2;
		r2_ = (l2 + r2) >> 1;
	}

	return cmp(u1_, l1_, r1_, mask1 & (~(1 << (bit - 1))), u2_, l2_, r2_, mask2 & (~(1 << (bit - 1))), bit - 1);
}
int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	pw[0] = 1;
	rep(i, 1, N - 1) pw[i] = LL(pw[i - 1]) * B % P;
	scanf("%d%s", &n, s);
	bud(1, 0, (1 << n) - 1, n);
	vector<int> id(1 << n);
	iota(id.begin(), id.end(), 0);
	sort(id.begin(), id.end(), [&](int lhs, int rhs) { return cmp(1, 0, (1 << n) - 1, lhs, 1, 0, (1 << n) - 1, rhs, n) < 0; });
	rep(i, 0, (1 << n) - 1) putchar(s[i ^ id[0]]);
	puts("");
}