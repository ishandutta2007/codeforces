/* by Hyperhydrochloric Acid */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); ++i)
#define cont(i, n)          for(int i = 1; i <= (n); ++i)
#define circ(i, a, b)       for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

const int qwq = 1 << 20;

template<int jt> struct ModInt {
	int x;
	ModInt(int v = 0) {x = v; if(x >= jt || x < 0) {x %= jt; if(x < 0) x += jt;}}
	ModInt(ll v) {x = v % jt; if(x < 0) x += jt;}
	operator int() const {return x;}
	friend inline ModInt &operator+=(ModInt &a, const ModInt &b) {a.x += b.x; if(a.x >= jt) a.x -= jt; return a;}
	friend inline ModInt operator+(ModInt a, const ModInt &b) {return a += b;}
	friend inline ModInt operator+(ModInt a, int b) {return a += ModInt(b);}
	friend inline ModInt operator+(int a, ModInt b) {return b += ModInt(a);}
	friend inline ModInt &operator++(ModInt &a) {return a += 1;}
	friend inline ModInt &operator-=(ModInt &a, const ModInt &b) {a.x -= b.x; if(a.x < 0) a.x += jt; return a;}
	friend inline ModInt operator-(ModInt a, const ModInt &b) {return a -= b;}
	friend inline ModInt operator-(ModInt a, int b) {return a -= ModInt(b);}
	friend inline ModInt operator-(int a, ModInt b) {return ModInt(a) - b;}
	friend inline ModInt &operator--(ModInt &a) {return a -= 1;}
	friend inline ModInt &operator*=(ModInt &a, const ModInt &b) {a.x = (ll)a.x * b.x % jt; return a;}
	friend inline ModInt operator*(ModInt a, const ModInt &b) {return a *= b;}
	friend inline ModInt operator*(ModInt a, int b) {return a *= ModInt(b);}
	friend inline ModInt operator*(int a, ModInt b) {return b *= ModInt(a);}
	static inline void exgcd(ll a, ll b, ll &x, ll &y) {b ? (exgcd(b, a % b, y, x), y -= a / b * x) : (x = 1, y = 0);}
	friend inline ModInt inv(const ModInt &a) {ll x, y; exgcd(a, jt, x, y); return x;}
	friend inline ModInt operator/(const ModInt &a, const ModInt &b) {return a * inv(b);}
	friend inline ModInt operator/(ModInt a, int b) {return a * inv(ModInt(b));}
	friend inline ModInt operator/(int a, ModInt b) {return ModInt(a) * inv(b);}
	friend inline ModInt operator/=(ModInt &a, const ModInt &b) {return a = a / b;}
};
const int jt = 1000000007;
typedef ModInt<jt> mint;

char tmp[qwq];
void inline gstr(string &s) {
	scanf("%s", tmp);
	s = tmp;
}

template<int ch, int jt> struct strHash {
	vector<int> ha, mii;
	void inline init(const string &s) {
		ha.clear(); mii.clear();
		ha.pub(0); mii.pub(1);
		loop(i, SZ(s)) {
			ha.pub((1ll * ha.back() * ch + s[i]) % jt);
			mii.pub(1ll * mii.back() * ch % jt);
		}
	}
	int inline get(int l, int r) {
		return (ha[r] - 1ll * mii[r - l + 1] * ha[l - 1] % jt + jt) % jt;
	}
};

int n, q, k;
string s, t, w;
vector<string> S;
mint sm[26][1 << 17];
mint mii[1 << 17];
strHash<233, 1000000007> ha1, hw1;
strHash<233, 998244353> ha2, hw2;

int main() {
	scanf("%d%d", &n, &q);
	gstr(s); gstr(t);
	S.pub(s); string tmp = s;
	loop(i, n) {
		tmp = tmp + t[i] + tmp;
		S.pub(tmp);
		if(SZ(tmp) > qwq) break;
	}
	loop(i, 26) loop(j, n) sm[i][j + 1] = sm[i][j] * 2 + (t[j] == i + 'a');
	mii[0] = 1;
	cont(i, n) mii[i] = mii[i - 1] * 2;
	while(q--) {
		scanf("%d", &k);
		gstr(w);
		int pos = 0;
		while(SZ(S[pos]) < SZ(w)) ++pos;
		if(pos > k) {
			puts("0"); continue;
		}
		ha1.init(S[pos]); ha2.init(S[pos]);
		hw1.init(w); hw2.init(w);
		int sw = SZ(w), si = SZ(S[pos]);
		int hh1 = hw1.get(1, sw);
		int hh2 = hw2.get(1, sw);
		mint ot = 0;
		cont(i, SZ(S[pos]) - sw + 1) if(ha1.get(i, i + sw - 1) == hh1 && ha2.get(i, i + sw - 1) == hh2) ++ot;
		ot *= mii[k - pos];
		vector<bool> pre(sw + 2), suf(sw + 2);
		pre[0] = suf[sw + 1] = 1;
		cont(i, sw) {
			if(ha1.get(si - i + 1, si) == hw1.get(1, i) && ha2.get(si - i + 1, si) == hw2.get(1, i)) {
				pre[i] = 1;
			}
			if(ha1.get(1, i) == hw1.get(sw - i + 1, sw) && ha2.get(1, i) == hw2.get(sw - i + 1, sw)) {
				suf[sw - i + 1] = 1;
			}
		}
		cont(i, sw) if(pre[i - 1] && suf[i + 1]) {
			int ch = w[i - 1] - 'a';
			ot += sm[ch][k] - sm[ch][pos] * mii[k - pos];
		}
		printf("%d\n", (int)ot);
	}
	return 0;
}