#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include <bits/stdc++.h>

using std::cin;
using std::cout;
typedef long long ll;
typedef std::vector <int> vector;
const int N = 1000054;

int n, q;
char s[N], *ptr;
int fy[N], qry[N], ans[N];
vector qs[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}

namespace PAM {
	int p, last, cnt;
	int d[N][26], fail[N], val[N];
	int stamp = 0, id[N], eid[N];
	int fst[N];
	vector ch[N];

	void init() {val[1] = -1, p = 0, *fail = cnt = 1;}	

	int get_fail(int x) {for (; ptr[~val[x]] != *ptr; x = fail[x]); return x;}

	int extend(int x) {
		int &q = d[p = get_fail(p)][x];
		if (!q) {
			fail[++cnt] = d[get_fail(fail[p])][x], val[q = cnt] = val[p] + 2;
			fst[cnt] = (val[cnt] <= val[fail[cnt]] * 2 ? fst[fail[cnt]] : cnt);
		}
		return p = q;
	}

	void child_init() {ch[1].emplace_back(0); for (int i = 2; i <= cnt; ++i) ch[fail[i]].emplace_back(i);}

	void dfs(int x) {id[x] = ++stamp; for (int y : ch[x]) dfs(y); eid[x] = stamp;}
}

namespace BIT {
	#define lowbit(x) (x & -x)
	int x[N];
	void add(int h, int v) {for (; h <= n; h += lowbit(h)) x[h] += v;}
	int sum(int h) {int s = 0; for (; h; h -= lowbit(h)) s += x[h]; return s;}
	inline void cover(int l, int r) {add(l, 1), add(r + 1, -1);}
}

namespace ST {
	int L;
	inline void init() {
		L = 1;
		for(;L < n;) L <<= 1;
	}
	#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
	int x[N * 4];

	inline void up(int p, int w) {
		p += L;
		for(;p;p >>= 1) ::up(x[p], w);
	}
	inline int range(int l, int r) {
		int res = 0;
		l += L, r += L;
		for(;l < r;l >>= 1, r >>= 1) {
			if((l & 1) == 1) ::up(res, x[l++]);
			if((r & 1) == 0) ::up(res, x[r--]);
		}
		if(l == r) ::up(res, x[l]);
		return res;
	}
}

int R[N];
inline void init() {
	int q;
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> q;
	::q = q;
	for(int i = 1, l = 1, r = 0;i <= q;++i) {
		char op[10];char c;
		cin >> op;
		if(op[1] == 'u') {
			cin >> s[++n];
			++ r;
		} else {
			++ l;
		}
		qry[i - 1] = l; R[i - 1] = r;
	}
}
char res[1 << 25], * out = res + (1 << 25);
inline void put(unsigned x) {
	do *--out = x % 10 + 48; while(x /= 10);
}
int main() {
	init();
	int i = 0, l, r;
	PAM::init();
	ST::init();
	for (ptr = s + 1; *ptr; ++ptr) fy[++i] = PAM::extend(*ptr - 97);
	PAM::child_init(), PAM::dfs(1);
	for (i = 0; i < q; ++i) qs[R[i]].emplace_back(i);
	for (r = 1; r <= n; ++r) {
		for (i = fy[r]; i; i = PAM::fail[PAM::fst[i]])
			l = ST::range(PAM::id[i], PAM::eid[i]),
			BIT::cover(std::max(l - PAM::val[i] + 2, 1), r - PAM::val[PAM::fst[i]] + 1);
		for (int id : qs[r]) ans[id] = BIT::sum(qry[id]);
		ST::up(PAM::id[fy[r]], r);
	}
	for(int i = q - 1;i >= 0;--i) *--out=10,put(ans[i]);
	fwrite(out, 1, (res + (1 << 25) - out), stdout);
	return 0;
}