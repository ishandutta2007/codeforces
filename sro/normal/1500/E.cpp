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

struct Dat {
	int sz;
	ll sm, psm, ssm;
	Dat(): sz(0), sm(0), psm(0), ssm(0) {}
	Dat(int sz, ll sm): sz(sz), sm(sm), psm(sm), ssm(sm) {}
	Dat(int sz, ll sm, ll psm, ll ssm): sz(sz), sm(sm), psm(psm), ssm(ssm) {}
	friend Dat inline operator + (const Dat &a, const Dat &b) {
		return Dat(a.sz + b.sz, a.sm + b.sm, a.psm + b.psm + b.sz * a.sm, a.ssm + a.sz * b.sm + b.ssm);
	}
};

const int maxn = 1 << 19;

struct Segtree {
	Dat dt[maxn << 1];
	void inline add(int a, const Dat &x) {
		dt[a += maxn] = x;
		while (a >>= 1) dt[a] = dt[a << 1] + dt[a << 1 | 1];
	}
	Dat inline sum(int l, int r) {
		Dat ls, rs;
		for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ls = ls + dt[l++];
			if (r & 1) rs = dt[--r] + rs;
		}
		return ls + rs;
	}
	Dat inline getpre(int x) {
		int now = 1;
		Dat pre;
		while (now < maxn) {
			if (x - pre.sz >= dt[now << 1].sz) pre = pre + dt[now << 1], now = now << 1 | 1;
			else now = now << 1;
		}
		return pre;
	}
	Dat inline getsuf(int x) {
		int now = 1;
		Dat suf;
		while (now < maxn) {
			if (x - suf.sz >= dt[now << 1 | 1].sz) suf = dt[now << 1 | 1] + suf, now = now << 1;
			else now = now << 1 | 1;
		}
		return suf;
	}
} seg;

int n, q;
vector<ll> vs;
ll s[maxn];
ll t[maxn], a[maxn];

int main() {
	scanf("%d%d", &n, &q);
	cont(i, n) scanf("%lld", s + i), vs.pub(s[i]);
	cont(i, q) scanf("%lld%lld", t + i, a + i), vs.pub(a[i]);
	sort(all(vs)); vs.erase(unique(all(vs)), vs.end());
	cont(i, n) {
		int pos = upper_bound(all(vs), s[i]) - vs.begin();
		seg.add(pos, Dat(1, s[i]));
	}
	int siz = n;
	loop(i, q + 1) {
		if (i) {
			int pos = upper_bound(all(vs), a[i]) - vs.begin();
			if (t[i] == 1) seg.add(pos, Dat(1, a[i])), ++siz;
			else seg.add(pos, Dat(0, 0)), --siz;
		}
		int l = 1, r = (siz + 1) / 2 + 1;
		while (r - l > 1) {
			int m = (l + r) >> 1;
			if (seg.getpre(m).sm - seg.getsuf(m - 1).sm >= 0) l = m;
			else r = m;
		}
		Dat ld = seg.getpre(l), rd = seg.getsuf(l - 1);
		ll res = seg.dt[1].sm - 2 * (ld.psm - rd.ssm);
		if (siz % 2 == 1 && l == (siz + 1) / 2) res += ld.sm - rd.sm;
		printf("%lld\n", res);
	}
	return 0;
}