#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

struct segtree {
	int sz;
	typedef int Val;
	vector<vector<Val> > dat;
	segtree(){}

	void init(vector<Val> num)
	{
		sz = 1;
		while (sz < num.size()) sz *= 2;
		dat.resize(sz * 2);

		rep(i, sz * 2) {
			dat[i].clear();
		}

		rep(i, num.size()) {
			dat[sz - 1 + i].pb(num[i]);
		}

		for (int i = sz - 2; i >= 0; --i) {
			int lc = i * 2 + 1, rc = i * 2 + 2;
			dat[i].resize(dat[lc].size() + dat[rc].size());
			merge(dat[lc].begin(), dat[lc].end(), dat[rc].begin(), dat[rc].end(), dat[i].begin());
		}
	}

	Val ask(int a, int b, int t, int k, int l, int r)
	{
		if (b <= l || r <= a) return 0;
		if (a <= l && r <= b) {
			return upper_bound(ALL(dat[k]), t) - dat[k].begin();
		}

		return ask(a, b, t, k * 2 + 1, l, (l + r) / 2) + ask(a, b, t, k * 2 + 2, (l + r) / 2, r);
	}

	Val ask(int a, int b, int t) {
		return ask(a, b, t, 0, 0, sz);
	}	
} seg[10010];

int n, k;
vector<int> vp[10010], val[10010];
vector<pair<int, pii>> st;
ll ret;

int main() {
	scanf("%d%d", &n, &k);
	st.resize(n);

	rep(i, n) {
		int x, r, f;
		scanf("%d%d%d", &x, &r, &f);
		st[i] = mp(x, mp(r, f));
	}

	sort(ALL(st));
	for (auto t : st) {
		vp[t.se.se].eb(t.fi);
		val[t.se.se].eb(t.fi - t.se.fi);
	}

	for (int i = 1; i <= 10000; ++i) {
		seg[i].init(val[i]);
	}

	for (auto t : st) {
		int up = t.fi + t.se.fi;
		int f = t.se.se;

		for (int ff = f - k; ff <= f + k; ++ff) {
			if (ff >= 1 && ff <= 10000) {
				int lb = upper_bound(ALL(vp[ff]), t.fi) - vp[ff].begin();
				int ub = upper_bound(ALL(vp[ff]), up) - vp[ff].begin();
				ret += seg[ff].ask(lb, ub, t.fi);
			}
		}
	}

	cout << ret << endl;

	return 0;
}