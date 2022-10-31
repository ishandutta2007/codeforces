#pragma GCC optimize("Ofast,03,unroll-loops")
#pragma GCC target("avx2")


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>
#include <array>
#include <cassert>
#include <string>
#include <map>
#include <complex>


using namespace std;

#define ll long long
#define flt double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define prcs cout << fixed << setprecision(10)
#define nlpt nullptr


const ll inf = 1e18;
mt19937 rnd(13123);


template<class T>
struct cmplx {
	T x, y;

	cmplx() : x(0), y(0) {}
	cmplx(const T& x, const T& y) : x(x), y(y) {}


	void operator/=(flt n) {
		x /= n;
		y /= n;
	}


	void operator/=(ll n) {
		x /= n;
		y /= n;
	}


	void operator/=(int n) {
		x /= n;
		y /= n;
	}


	void operator+=(const cmplx& c) {
		x += c.x;
		y += c.y;
	}


	cmplx<T> rev() const {
		return cmplx<T>(x, -y);
	}


	void muli() {
		swap(x, y);
		x = -x;
	}


	void rv_muli() {
		x = -x;
		swap(x, y);
	}
};


template<class T>
cmplx<T> operator+(const cmplx<T>& a, const cmplx<T>& b) {
	return cmplx<T>(a.x + b.x, a.y + b.y);
}


template<class T>
cmplx<T> operator-(const cmplx<T>& a, const cmplx<T>& b) {
	return cmplx<T>(a.x - b.x, a.y - b.y);
}


template<class T>
cmplx<T> operator*(const cmplx<T>& a, const cmplx<T>& b) {
	return cmplx<T>(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}


template<class T>
cmplx<T> operator/(const cmplx<T>& a, const T& b) {
	return cmplx<T>(a.x / b, a.y / b);
}



template<class T>
T abs(const cmplx<T>& a) {
	return sqrt(a.x * a.x + a.y * a.y);
}


template<class T>
T abs2(const cmplx<T>& a) {
	return a.x * a.x + a.y * a.y;
}


template<class T>
cmplx<T> operator/(const cmplx<T>& a, const cmplx<T>& b) {
	return a * b.rev() / abs2(b);
}


typedef cmplx<flt> base;


const flt PI = atan2(0, -1);
const int mxlg = 19;
vector<int> rev;
vector<base> w;


void build_rev() {
	rev.resize(1 << mxlg);
	rev[0] = 0;
	for (int i = 0; i < (1 << mxlg); i += 1) {
		rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (mxlg - 1));
	}
}


void build_w() {
	w.resize(1 << (mxlg - 1));
	int n = (1 << (mxlg - 1));
	for (int i = 0; i < n; i += 1) {
		flt angl = (PI * i) / n;
		w[i] = base(cos(angl), sin(angl));
	}
}


void pre_cnt() {
	build_rev();
	build_w();
}


void fft(vector<base>& a, int nk) {
	int n = (1 << nk);
	int dk = mxlg - nk;
	for (int i = 0; i < n; i += 1) {
		int t = (rev[i] >> dk);
		if (i < t) {
			swap(a[i], a[t]);
		}
	}
	for (int lnk = 0; lnk < nk; lnk += 1) {
		int ln = (1 << lnk);
		int stp = (mxlg - 1 - lnk);
		for (int i = 0; i < n; i += (ln << 1)) {
			for (int j = 0; j < ln; j += 1) {
				auto& mw = w[j << stp];
				int ij = i + j;
				int ijln = ij + ln;
				auto x = a[ij];
				auto y = a[ijln] * mw;
				a[ij] += y;
				a[ijln] = x - y;
			}
		}
	}
}


void fft2(vector<base>& f, vector<base>& resa, vector<base>& resb, int nk) {
	int n = (1 << nk);
	fft(f, nk);
	resa.resize(n);
	resb.resize(n);
	for (int i = 0; i < n; ++i) {
		int s = n - i;
		if (i == 0) {
			s = 0;
		}
		auto& fi = f[i];
		auto fsrv = f[s].rev();
		resa[i] = (f[i] + f[s].rev());
		resa[i] /= 2;
		resb[i] = (f[s].rev() - f[i]);
		resb[i] /= 2;
		resb[i].muli();
	}
}


void fft2(vector<ll>& a, vector<ll>& b, vector<base>& fa, vector<base>& fb, int nk) {
	int n = (1 << nk);
	vector<base> t(n);
	for (int i = 0; i < n; i += 1) {
		if (i < a.size()) {
			t[i].x = a[i];
		}
		if (i < b.size()) {
			t[i].y = b[i];
		}
	}
	fft2(t, fa, fb, nk);
}


void fst_fft(vector<ll>& a, vector<base>& fa, int nk) {
	if (nk == 0) {
		fa.resize(1);
		fa[0] = base(a[0], 0);
		fft(fa, nk);
		return;
	}
	int n = (1 << (nk - 1));
	int asz = a.size();
	a.resize(n + n, 0);
	vector<base> b(n);
	for (int i = 0; i < n; i += 1) {
		b[i] = base(a[i + i], a[i + i + 1]);
	}
	vector<base> f0, f1;
	fft2(b, f0, f1, nk - 1);
	fa.resize(n + n);
	for (int i = 0; i < n; i += 1) {
		fa[i] = f0[i];
		fa[i + n] = f1[i];
	}
	for (int lnk = nk - 1; lnk < nk; lnk += 1) {
		int ln = (1 << lnk);
		int stp = (mxlg - 1 - lnk);
		for (int i = 0; i < n + n; i += (ln << 1)) {
			for (int j = 0; j < ln; j += 1) {
				auto& mw = w[j << stp];
				int ij = i + j;
				int ijln = ij + ln;
				auto x = fa[ij];
				auto y = fa[ijln] * mw;
				fa[ij] += y;
				fa[ijln] = x - y;
			}
		}
	}
	a.resize(asz);
}


void rev_fft(vector<base>& a, int nk) {
	int n = (1 << nk);
	fft(a, nk);
	for (int i = 0; i < n; i += 1) {
		a[i] /= n;
	}
	reverse(a.begin() + 1, a.end());
}


void rev_fft2(vector<base>& resa, vector<base>& resb, vector<base>& f, int nk) {
	int n = (1 << nk);
	f.resize(n);
	for (int i = 0; i < n; ++i) {
		int s = n - i;
		if (i == 0) {
			s = 0;
		}
		auto rsa = resa[i];
		auto rsb = resb[i];
		rsb.muli();
		f[i] = rsa + rsb;
	}
	rev_fft(f, nk);
}


void fst_rev_fft(vector<base>& fa, vector<ll>& a, int nk) {
	if (nk <= 1) {
		rev_fft(fa, nk);
		int n = (1 << nk);
		a.resize(n);
		for (int i = 0; i < n; i += 1) {
			a[i] = llround(fa[i].x);
		}
		return;
	}
	int n = (1 << (nk - 1));
	for (int lnk = nk - 1; lnk < nk; lnk += 1) {
		int ln = (1 << lnk);
		int stp = (mxlg - 1 - lnk);
		for (int i = 0; i < n + n; i += (ln << 1)) {
			for (int j = 0; j < ln; j += 1) {
				auto& mw = w[j << stp];
				int ij = i + j;
				int ijln = ij + ln;
				auto x = (fa[ij] + fa[ijln]);
				x /= 2;
				auto y = (fa[ij] - fa[ijln]) / mw;
				y /= 2;
				fa[ij] = x;
				fa[ijln] = y;
			}
		}
	}
	vector<base> f0(n), f1(n);
	for (int i = 0; i < n; i += 1) {
		f0[i] = fa[i];
		f1[i] = fa[i + n];
	}
	vector<base> b(n);
	rev_fft2(f0, f1, b, nk - 1);
	a.resize(n + n);
	for (int i = 0; i < n; i += 1) {
		a[i + i] = llround(b[i].x);
		a[i + i + 1] = llround(b[i].y);
	}
}


vector<base> ma, mb, mc;


void mul_plnms(vector<ll>& a, vector<ll>& b, vector<ll>& c) {
	int asz = a.size();
	int bsz = b.size();
	int nk = 0;
	while ((1 << nk) < asz + bsz - 1) {
		nk += 1;
	}
	int n = (1 << nk);
	mc.resize(n);
	fft2(a, b, ma, mb, nk);
	for (int i = 0; i < n; i += 1) {
		mc[i] = ma[i] * mb[i];
	}
	fst_rev_fft(mc, c, nk);
	c.resize(asz + bsz - 1);
}


void mul_plnms(vector<base> a, vector<base> b, vector<base>& c) {
	int asz = a.size();
	int bsz = b.size();
	int nk = 0;
	while ((1 << nk) < asz + bsz - 1) {
		nk += 1;
	}
	int n = (1 << nk);
	a.resize(n);
	b.resize(n);
	c.resize(n);
	fft(a, nk);
	fft(b, nk);
	for (int i = 0; i < n; i += 1) {
		c[i] = a[i] * b[i];
	}
	rev_fft(c, nk);
	c.resize(asz + bsz - 1);
}


string mul_nmbrs(string a, string b) {
	int ngtv = 0;
	if (a[0] == '-') {
		ngtv ^= 1;
		a = string(a.begin() + 1, a.end());
	}
	if (b[0] == '-') {
		ngtv ^= 1;
		b = string(b.begin() + 1, b.end());
	}
	vector<ll> va(a.size()), vb(b.size());
	for (int i = 0; i < a.size(); i += 1) {
		va[i] = a[i] - '0';
	}
	for (int i = 0; i < b.size(); i += 1) {
		vb[i] = b[i] - '0';
	}
	reverse(all(va));
	reverse(all(vb));
	vector<ll> vc;
	mul_plnms(va, vb, vc);
	for (int i = 0; i < vc.size(); i += 1) {
		if (vc[i] >= 10) {
			if (i + 1 >= vc.size()) {
				vc.push_back(0);
			}
			vc[i + 1] += vc[i] / 10;
			vc[i] %= 10;
		}
	}
	while (vc.size() > 1 && vc.back() == 0) {
		vc.pop_back();
	}
	reverse(all(vc));
	string c;
	c.resize(vc.size());
	for (int i = 0; i < vc.size(); i += 1) {
		c[i] = (char)(vc[i] + '0');
	}
	if (ngtv && (c != "0")) {
		c = string("-") + c;
	}
	return c;
}


const int alph = 26;


flt eps = 1e-5;


void is_ok(vector<base>& a, vector<base>& b, vector<int>& gd, int n, int m) {
	vector<base> c;
	mul_plnms(a, b, c);
	for (int i = 0; i <= n - m; i += 1) {
		if (c[i + m - 1].x + eps < m) {
			gd[i] = 0;
		}
	}
}


int32_t main() {
	if (1) {
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	}
	pre_cnt();
	vector<int> p(alph);
	for (int i = 0; i < alph; i += 1) {
		cin >> p[i];
		--p[i];
	}
	string s, t;
	cin >> t;
	cin >> s;
	int n = s.size();
	int m = t.size();
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i += 1) {
		a[i] = s[i] - 'a';
	}
	for (int j = 0; j < m; j += 1) {
		b[j] = t[j] - 'a';
	}
	vector<vector<base>> d(alph);
	d.resize(alph);
	int nk = 0; 
	vector<int> gd(n - m + 1, 1);
	vector<base> fa(n), fb(m);
	int c = 0;
	vector<int> usd(alph, 0);
	vector<int> cmp(alph);
	vector<int> cmpsz;
	for (int i = 0; i < alph; i += 1) {
		if (!usd[i]) {
			int v = i;
			int sz = 0;
			while (1) {
				usd[v] = 1;
				cmp[v] = c;
				sz += 1;
				v = p[v];
				if (v == i) {
					break;
				}
			}
			cmpsz.push_back(sz);
			c += 1;
		}
	}
	for (int i = 0; i < n; i += 1) {
		flt ang = cmp[a[i]] * (PI / alph);
		fa[i] = base(cos(ang), sin(ang));
	}
	for (int i = 0; i < m; i += 1) {
		flt ang = -cmp[b[i]] * (PI / alph);
		fb[i] = base(cos(ang), sin(ang));
	}
	reverse(all(fb));
	is_ok(fa, fb, gd, n, m);
	usd.assign(alph, 0);
	vector<base> s1(alph), s2(alph);
	for (int i = 0; i < alph; i += 1) {
		if (!usd[i]) {
			int v = i;
			int c = cmp[v];
			int sz = cmpsz[c];
			if (sz <= 2) {
				while (1) {
					usd[v] = 1;
					s1[v] = base(1, 0);
					s2[v] = base(1, 0);
					v = p[v];
					if (v == i) {
						break;
					}
				}
				continue;
			}
			flt ang = (2 * PI / sz);
			flt d = cos(ang / 2);
			int j = 0;
			while (1) {
				usd[v] = 1;
				s1[v] = base(cos(ang * j - ang / 2), sin(ang * j - ang / 2));
				s2[v] = base(cos(-ang * j), sin(-ang * j)) / d;
				v = p[v];
				j += 1;
				if (v == i) {
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; i += 1) {
		fa[i] = s1[a[i]];
	}
	for (int i = 0; i < m; i += 1) {
		fb[i] = s2[b[i]];
	}
	reverse(all(fb));
	is_ok(fa, fb, gd, n, m);
	for (int i = 0; i <= n - m; i += 1) {
		cout << (gd[i]);
	}
	cout << "\n";
	return 0;
}

/*
2 3 1 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
abc
abcaabaff

*/