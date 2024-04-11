#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

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
int a[200005];
int sm[200005], smm[10][200005];
vector<int> mis[10];

vector<int> inline charge(const vector<pair<int, int> > &v) {
	vector<int> ans(SZ(v) + 1, 0);
	for (int i = 0; i < SZ(v); ++i) {
		vector<int> dx(SZ(v) + 1, 0);
		dx[0] = 1;
		int fm = 1;
		for (int j = 0; j < SZ(v); ++j) if (i != j) {
			for (int k = SZ(v); ~k; --k) {
				mul(dx[k], v[j].first);
				if (k) sub(dx[k], dx[k - 1]);
			}
			mul(fm, Sub(v[j].first, v[i].first));
		}
		fm = ksmii(fm, jt - 2);
		mul(fm, v[i].second);
		for (int k = 0; k <= SZ(v); ++k) mul(dx[k], fm);
		for (int k = 0; k <= SZ(v); ++k) add(ans[k], dx[k]);
	}
	return ans;
}

int inline _getv(int r, int k) {
	int s = 0, m = 1;
	for (int i = 0; i < SZ(mis[k]); ++i) {
		add(s, Mul(mis[k][i], m));
		mul(m, r);
	}
	return s;
}

int inline getval(int l, int s, int d, int k) {
	if (!d) return Mul(ksmii(l, k + 2), s);
	mul(l, ksmii(d, jt - 2));
	return Mul(ksmii(d, k + 2), Sub(_getv(Add(l, s - 1), k), _getv(Sub(l, 1), k)));
}

int main() {
	srand(time(0));
	scanf("%d%d", &N, &Q);
	int f2 = ksmii(2, jt - 2);
	for (int i = 1; i <= N; ++i) scanf("%d", a + i), sm[i] = Add(sm[i - 1], a[i]);
	for (int k = 0; k < 10; ++k) for (int i = 1; i <= N; ++i) smm[k][i] = Add(smm[k][i - 1], ksmii(a[i], k + 2));
	for (int k = 0; k < 10; ++k) {
		vector<pair<int, int> > vs;
		int he = 0;
		for (int i = 0; i <= k + 3; ++i) {
			add(he, ksmii(i, k + 2));
			vs.emplace_back(i, he);
		}
		mis[k] = charge(vs);
	}
	while (Q--) {
		int l, r, d;
		scanf("%d%d%d", &l, &r, &d);
		int as = Sub(sm[r], sm[l - 1]);
		mul(as, 2);
		sub(as, Mul(d, Mul(r - l, r - l + 1)));
		mul(as, Mul(f2, ksmii(r - l + 1, jt - 2)));
		bool can = 1;
		for (int k = 0; k < 10; ++k) {
			int dx = getval(as, r - l + 1, d, k);
			int nv = Sub(smm[k][r], smm[k][l - 1]);
			if (dx != nv) can = 0;
		}
		puts(can ? "Yes" : "No");
	}
	return 0;
}