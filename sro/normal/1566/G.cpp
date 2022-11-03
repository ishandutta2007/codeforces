#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

const int maxn = 1 << 17;

struct SegtreeNode {
	pair<ll, int> val[3];
	SegtreeNode() { rep(i, 3) val[i] = make_pair(1e18, -i); }
	SegtreeNode(pair<ll, int> nv[]) { memcpy(val, nv, sizeof(val)); }
	SegtreeNode operator + (const SegtreeNode &t) const {
		SegtreeNode nt = *this;
		rep(i, 3) {
			pair<ll, int> tv = t.val[i];
			if (tv.first < nt.val[0].first) swap(nt.val[0], tv);
			if ((tv.second != nt.val[0].second && tv.first < nt.val[1].first) || nt.val[0].second == nt.val[1].second) swap(nt.val[1], tv);
			if ((tv.second != nt.val[0].second && tv.second != nt.val[1].second && tv.first < nt.val[2].first) || nt.val[0].second == nt.val[2].second || nt.val[1].second == nt.val[2].second) swap(nt.val[2], tv);
		}
		return nt;
	}
};

struct Segtree {
	SegtreeNode dt[maxn << 1];
	void inline modify(int a, const SegtreeNode &x) {
		dt[a += maxn] = x;
		while (a >>= 1) dt[a] = dt[a << 1] + dt[a << 1 | 1];
	}
} seg;

int N, M;
set<pair<ll, int> > egs[maxn];
set<tuple<int, int, int> > Es, Ws;
ll s[maxn];
pair<ll, int> m3[maxn][3];
multiset<ll> mns;

void inline operdo(int i, bool add) {
	if (add) {
		s[i] = 0;
		auto it = egs[i].begin();
		rep(j, 3) s[i] += it->first, m3[i][j] = *it, ++it;
		seg.modify(i, m3[i]);
		mns.insert(s[i]);
	}
	else mns.erase(mns.find(s[i]));
}

ll inline query() {
	ll res = *mns.begin();
	int mu, mv, mw; tie(mw, mu, mv) = *Ws.begin();
	seg.modify(mu, SegtreeNode());
	seg.modify(mv, SegtreeNode());
	rep(i, 3) {
		pair<ll, int> tv = seg.dt[1].val[i];
		if (tv.second != mu && tv.second != mv) res = min(res, tv.first + mw);
	}
	seg.modify(mu, m3[mu]);
	seg.modify(mv, m3[mv]);
	rep(i, 3) if (m3[mu][i].second != mv) rep(j, 3)  if (m3[mv][j].second != mu && m3[mv][j].second != m3[mu][i].second) {
		res = min(res, m3[mu][i].first + m3[mv][j].first);
	}
	return res;
}

int main() {
	scanf("%d%d", &N, &M);
	repi(i, N) rep(j, 3) egs[i].emplace(1e18, -j);
	repi(i, M) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		if (u > v) swap(u, v);
		egs[u].emplace(w, v);
		egs[v].emplace(w, u);
		Es.emplace(u, v, w);
		Ws.emplace(w, u, v);
	}
	repi(i, N) operdo(i, 1);
	printf("%lld\n", query());
	int q; scanf("%d", &q);
	while (q--) {
		int op;
		scanf("%d", &op);
		if (!op) {
			int u, v; scanf("%d%d", &u, &v);
			if (u > v) swap(u, v);
			auto eg = Es.lower_bound(make_tuple(u, v, -114514));
			int w = get<2>(*eg);
			operdo(u, 0); operdo(v, 0);
			Es.erase(eg); Ws.erase(make_tuple(w, u, v));
			egs[u].erase(make_pair(w, v));
			egs[v].erase(make_pair(w, u));
			operdo(u, 1); operdo(v, 1);
		}
		else {
			int u, v, w; scanf("%d%d%d", &u, &v, &w);
			if (u > v) swap(u, v);
			operdo(u, 0); operdo(v, 0);
			Es.emplace(u, v, w);
			Ws.emplace(w, u, v);
			egs[u].emplace(w, v);
			egs[v].emplace(w, u);
			operdo(u, 1); operdo(v, 1);
		}
		printf("%lld\n", query());
	}
	return 0;
}