#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define foreach(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

int n, m, p;
int s[50005];
ll k;

void inline add(int &a, int b) {
	a += b - p;
	a += (a >> 31) & p;
}

struct Matrix {
	int a[2][2];
	Matrix() { memset(a, 0, sizeof(a)); }
	Matrix(int x) { loop(i, 2) loop(j, 2) a[i][j] = x * (i == j); }
	Matrix(int A, int b, int c, int d) {
		a[0][0] = A;
		a[0][1] = b;
		a[1][0] = c;
		a[1][1] = d;
	}
	const int inline *operator[](int x) const { return a[x]; }
	int inline *operator[](int x) { return a[x]; }
	Matrix operator*(const Matrix &m) const {
		Matrix res;
		loop(i, 2) loop(j, 2) loop(k, 2) add(res[i][k], 1ll * a[i][j] * m[j][k] % p);
		return res;
	}
	void debug() { cerr << '{' << a[0][0] << ' ' << a[0][1] << ' ' << a[1][0] << ' ' << a[1][1] << "}\n"; }
};

const int maxn = 1 << 16;

struct ZkwSeg {
	Matrix dt[maxn << 1];
	void inline add(int a, const Matrix &x) {
		dt[a += maxn] = x;
		while (a >>= 1) dt[a] = dt[a << 1] * dt[a << 1 | 1];
	}
	Matrix inline get(int l, int r) {
		Matrix lans(1), rans(1);
		for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) lans = lans * dt[l++];
			if (r & 1) rans = dt[--r] * rans;
		}
		return lans * rans;
	}
} seg;

Matrix ksmii(const Matrix &a, ll b) {
	if (!b) return 1;
	Matrix x = ksmii(a, b >> 1);
	x = x * x;
	if (b & 1) x = x * a;
	return x;
}

Matrix zh(1);

Matrix wget(ll l, ll r) {
	int lm = l % n, rm = r % n;
	if (l > r) return 1;
	if (l / n == r / n) return seg.get(lm, rm);
	return seg.get(lm, n - 1) * ksmii(zh, r / n - l / n - 1) * seg.get(0, rm);
}

int main() {
	scanf("%lld%d%d", &k, &p, &n);
	// p = 19260817;
	loop(i, n) scanf("%d", s + i);
	Matrix tmp;
	loop(i, n) {
		Matrix mat(0, s[i], 1, s[(i + 1) % n]);
		seg.add(i, mat);
		zh = zh * mat;
	}
	vector<pair<ll, int> > sh;
	scanf("%d", &m);
	while (m--) {
		ll a;
		int b;
		scanf("%lld%d", &a, &b);
		if (a <= k) sh.emb(a, b);
	}
	sort(all(sh));
	vector<pair<ll, ll> > ar;
	vector<Matrix> ms;
	ll tm = 0;
	loop(i, SZ(sh)) {
		int r = i;
		while (r < SZ(sh) - 1 && sh[r + 1].first == sh[r].first + 1) ++r;
		ll ls = sh[i].first, rs = sh[r].first;
		tmp = Matrix(0, s[(ls + n - 1) % n], 1, sh[i].second);
		circ(j, i, r - (rs == k)) {
			Matrix mm(0, sh[j].second, 1, j < r ? sh[j + 1].second : s[(rs + 1) % n]);
			tmp = tmp * mm;
		}
		ms.pub(tmp);
		ar.emb(tm, ls - 1);
		tm = rs + 1;
		i = r;
	}
	if (tm > k) --tm;
	ar.emb(tm, k);
	Matrix res(1);
	loop(i, SZ(ar)) {
		res = res * wget(ar[i].first, ar[i].second - 1);
		if (i < SZ(ms)) res = res * ms[i];
	}
	printf("%d\n", (Matrix(0, 1, 0, 0) * res)[0][0]);
	return 0;
}

/**
 * 
 *  
 *  
 *   K 
 */