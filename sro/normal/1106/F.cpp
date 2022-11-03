#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for(int i = 0; i < (a); ++i)
#define cont(i, a) for(int i = 1; i <= (a); ++i)
#define circ(i, a, b) for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for(int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define foreach(it, x) for(auto it = (x).begin(); it != (x).end(); ++it)
#define pub push_back
#define pob pop_back
#define mak make_pair
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct HashTab {
	const static int jt = 19260817;
	int head[jt], key[2000005], val[2000005], nxt[2000005], nds;
	int inline &operator[](int k) {
		int kk = k % jt;
		int id = head[kk];
		while(id && key[id] != k) id = nxt[id];
		if(id) return val[id];
		++nds;
		nxt[nds] = head[kk];
		head[kk] = nds; key[nds] = k; val[nds] = 0;
		return val[nds];
	}
	int inline access(int k) {
		int kk = k % jt;
		int id = head[kk];
		while(id && key[id] != k) id = nxt[id];
		if(id) return val[id];
		return -1;
	}
} mp;

const int jt = 998244353, rg = 859, bsz = 33000;

int ksmii(int a, int b) {
	if(!b) return 1;
	int x = ksmii(a, b >> 1);
	x = 1ll * x * x % jt;
	if(b & 1) x = 1ll * x * a % jt;
	return x;
}

void init_bsgs() {
	int per = ksmii(rg, bsz), mii = 1;
	range(ts, bsz, jt, bsz) {
		mii = 1ll * mii * per % jt;
		int &val = mp[mii];
		if(!val) val = ts;
	}
}

int bsgs(int x) {
	if(x == 1) return 0;
	int bg = x, res = Inf;
	loop(i, bsz) {
		int pos = mp.access(bg);
		if(~pos) res = min(res, pos - i);
		bg = 1ll * bg * rg % jt;
	}
	return res;
}

template<int siz> struct Matrix {
	int a[siz][siz];
	const int *operator[](int x) const {return a[x];}
	int *operator[](int x) {return a[x];}
	Matrix(int x = 0) {loop(i, siz) loop(j, siz) a[i][j] = (i == j) * x;}
	Matrix operator*(const Matrix &mat) const {
		static Matrix res; res = Matrix();
		loop(i, siz) loop(j, siz) loop(k, siz) res[i][k] = (res[i][k] + 1ll * a[i][j] * mat[j][k]) % (jt - 1);
		return res;
	}
	Matrix &operator*=(const Matrix &mat) {
		return *this = *this * mat;
	}
};
typedef Matrix<105> matrix;

matrix qp(matrix a, int b) {
	matrix res = 1;
	while(b) {
		if(b & 1) res *= a;
		a *= a; b >>= 1;
	}
	return res;
}

int inline gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

void inline exgcd(int a, int b, ll &x, ll &y) {
	b ? (exgcd(b, a % b, y, x), y -= a / b * x) : (x = 1, y = 0);
}

int k, n, m;
int b[105];
matrix tr;

int main() {
	scanf("%d", &k);
	cont(i, k) scanf("%d", b + i);
	scanf("%d%d", &n, &m);
	init_bsgs();
	m = bsgs(m);
	cont(i, k) tr[1][i] = b[i];
	cont(i, k - 1) tr[i + 1][i] = 1;
	tr = qp(tr, n - k);
	int xi = tr[1][1], g;
	if(gcd(xi, m) % (g = gcd(xi, jt - 1))) return puts("-1"), 0;
	ll x, y; exgcd(xi, jt - 1, x, y);
	x %= jt - 1; if(x < 0) x += jt - 1;
	printf("%d\n", ksmii(rg, x * (m / g) % (jt - 1)));
	return 0;
}