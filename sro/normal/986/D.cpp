#pragma GCC optimize(3)
#pragma GCC optimize("-Ofast")
#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for(int i = 0; i < (a); ++i)
#define cont(i, a) for(int i = 1; i <= (a); ++i)
#define circ(i, a, b) for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for(int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define foreach(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define pub push_back
#define pob pop_back
#define mak make_pair
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

const int jt = 998244353, rg = 3;

void inline add(int &a, int b) {
	a += b - jt; a += (a >> 31) & jt;
}

int inline ksmii(int a, int b) {
	if(!b) return 1;
	int x = ksmii(a, b >> 1);
	x = 1ll * x * x % jt;
	if(b & 1) x = 1ll * x * a % jt;
	return x;
}

void inline fft(vector<int> &a, int inv) {
	int lg = 0, n = SZ(a); vector<int> ho(n, 0);
	while((1 << lg) < n) ++lg;
	loop(i, n) {
		ho[i] = (ho[i >> 1] >> 1) | ((i & 1) << (lg - 1));
		if(i < ho[i]) swap(a[i], a[ho[i]]);
	}
	range(i, 1, n - 1, i) {
		int omega = ksmii(rg, (jt - 1) / (i << 1));
		range(j, 0, n - 1, i << 1) {
			int omg = 1;
			loop(k, i) {
				int tmp = 1ll * omg * a[j + k + i] % jt;
				a[j + k + i] = a[j + k];
				add(a[j + k + i], jt - tmp);
				add(a[j + k], tmp);
				omg = 1ll * omg * omega % jt;
			}
		}
	}
	if(!~inv) {
		reverse(a.begin() + 1, a.end());
		int fn = ksmii(n, jt - 2);
		loop(i, n) a[i] = 1ll * a[i] * fn % jt;
	}
}

char tmp[1 << 21];

struct Bignum: vector<int> {
	#define sz ((int)size())

	Bignum() {}
	Bignum(int x) {
		while(x) {
			pub(x % 10);
			x /= 10;
		}
	}
	bool inline operator<(const Bignum &b) const {
		if(sz != SZ(b)) return sz < SZ(b);
		range(i, sz - 1, 0, -1) if(at(i) != b[i]) return at(i) < b[i];
		return 0;
	}
	bool inline operator>(const Bignum &b) const {
		if(sz != SZ(b)) return sz > SZ(b);
		range(i, sz - 1, 0, -1) if(at(i) != b[i]) return at(i) > b[i];
		return 0;
	}
	bool inline operator==(const Bignum &b) const {
		if(sz != SZ(b)) return 0;
		range(i, sz - 1, 0, -1) if(at(i) != b[i]) return 0;
		return 1;
	}
	bool inline operator>=(const Bignum &b) const {return !(*this < b);}
	bool inline operator<=(const Bignum &b) const {return !(*this > b);}
	Bignum inline &operator*=(int x) {
		loop(i, sz) at(i) *= x;
		loop(i, sz) {
			if(at(i) >= 10 && i == sz - 1) pub(0);
			if(at(i) >= 10) at(i + 1) += at(i) / 10;
			at(i) %= 10;
		}
		return *this;
	}
	Bignum inline &operator*=(const Bignum &b) {
		if(sz + SZ(b) <= 512) {
			Bignum res; res.resize(sz + SZ(b) - 1);
			loop(i, sz) loop(j, SZ(b)) res[i + j] += at(i) * b[j];
			loop(i, SZ(res)) {
				if(res[i] >= 10 && i == SZ(res) - 1) res.pub(0);
				if(res[i] >= 10) res[i + 1] += res[i] / 10;
				res[i] %= 10;
			}
			return *this = res;
		}
		vector<int> A, B;
		loop(i, sz) A.pub(at(i));
		loop(i, SZ(b)) B.pub(b[i]);
		int siz = 1, as = sz + SZ(b) - 1;
		while(siz <= as) siz <<= 1;
		A.resize(siz); B.resize(siz);
		fft(A, 1); fft(B, 1);
		loop(i, siz) A[i] = 1ll * A[i] * B[i] % jt;
		fft(A, -1);
		resize(siz); loop(i, siz) at(i) = A[i];
		loop(i, sz) {
			if(at(i) >= 10 && i == sz - 1) pub(0);
			if(at(i) >= 10) at(i + 1) += at(i) / 10;
			at(i) %= 10;
		}
		while(sz && !back()) pob();
		return *this;
	}
	Bignum inline &sqr() {
		vector<int> A;
		loop(i, sz) A.pub(at(i));
		int siz = 1, as = sz + sz - 1;
		while(siz <= as) siz <<= 1;
		A.resize(siz); fft(A, 1);
		loop(i, siz) A[i] = 1ll * A[i] * A[i] % jt;
		fft(A, -1);
		resize(siz); loop(i, siz) at(i) = A[i];
		loop(i, sz) {
			if(at(i) >= 10 && i == sz - 1) pub(0);
			if(at(i) >= 10) at(i + 1) += at(i) / 10;
			at(i) %= 10;
		}
		while(sz && !back()) pob();
		return *this;
	}
	Bignum inline &operator/=(int x) {
		range(i, sz - 1, 0, -1) {
			if(i) at(i - 1) += at(i) % x * 10;
			at(i) /= x;
		}
		while(sz && !back()) pob();
		return *this;
	}
	void inline write() {
		if(!sz) putchar('0');
		range(i, sz - 1, 0, -1) putchar(at(i) + '0');
	}
	void inline read() {
		scanf("%s", tmp);
		int m = strlen(tmp);
		resize(m);
		range(i, m - 1, 0, -1) at(m - 1 - i) = tmp[i] - '0';
		while(sz && !back()) pob();
	}

	#undef sz
};

Bignum res;

void inline qp(int a, int b) {
	if(!b) return void(res = 1);
	qp(a, b >> 1);
	res.sqr(); if(b & 1) res *= a;
}

Bignum n, m;

int main() {
	n.read();
	if(n <= 4) return n.write(), 0;
	int lg = SZ(n) / log10(3) - 1;
	int mii = lg;
	qp(3, lg); m = res;
	while(m < n) ++mii, m *= 3;
	n *= 3; int ans = mii * 3;
	cont(s2, 2) {
		m *= 2;
		while(m >= n) --mii, m /= 3;
		ans = min(ans, mii * 3 + s2 * 2);
	}
	printf("%d\n", ans);
	return 0;
}