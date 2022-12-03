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

const int SZ = 1 << 19;

struct segtree {
	vector<int> dat;

	void init() {
		dat.resize(SZ * 2);
		rep(i, SZ * 2) dat[i] = -1;
	}

	void update(int pos, int x) {
		pos += SZ - 1;
		dat[pos] = x;

		while (pos > 0) {
			pos = (pos - 1) / 2;
			dat[pos] = max(dat[pos * 2 + 1], dat[pos * 2 + 2]);
		}
	}

	int get(int a, int b, int k = 0, int l = 0, int r = SZ) {
		if (b <= l || r <= a) return INT_MIN;
		if (a <= l && r <= b) return dat[k];
		return max(get(a, b, k * 2 + 1, l, (l + r) / 2), get(a, b, k * 2 + 2, (l + r) / 2, r));
	}
} seg;

typedef pair<ll, ll> pll;

pll norm(const pll& a)
{
	ll x = a.fi, y = a.se;
	if (x == 0) y = 1;
	else {
		ll d = __gcd(abs(x), y);
		x /= d; y /= d;
	}
	return mp(x, y);
}

bool cmp(const pll& a, const pll& b)
{
	return (a.fi * b.se - b.fi * a.se) > 0LL;
}

int n, R;
pii ang[500010];
multiset<int> ps[500010];

void add(pii p)
{
	ps[p.fi].insert(p.se);
	seg.update(p.fi, *ps[p.fi].rbegin());
}

void del(pii p)
{
	ps[p.fi].erase(ps[p.fi].lower_bound(p.se));
	if (ps[p.fi].size() == 0) {
		seg.update(p.fi, -1);
	} else {
		seg.update(p.fi, *ps[p.fi].rbegin());
	}
}

int main() {
	scanf("%d %d", &R, &n);
	vector<pair<int, pii>> vec(n);
	vector<pll> vl, vr;

	rep(i, n) {
		int tp;
		scanf("%d", &tp);
		if (tp == 1) {
			int x, y;
			scanf("%d %d", &x, &y);

			vl.pb(mp(x + R, y));
			vr.pb(mp(-(x - R), y));
			vec[i] = mp(1, mp(x, y));
		} else if (tp == 2) {
			int id;
			scanf("%d", &id);
			--id;
			vec[i] = mp(2, mp(id, -1));
		} else {
			int p, q;
			scanf("%d %d", &p, &q); --p; --q;
			vec[i] = mp(3, mp(p, q));
		}
	}

	rep(i, vl.size()) vl[i] = norm(vl[i]);
	rep(i, vr.size()) vr[i] = norm(vr[i]);

	sort(ALL(vl), cmp);
	sort(ALL(vr), cmp);

	int now = 0;
	seg.init();

	for (auto tt : vec) {
		if (tt.fi == 1) {
			ll x = tt.se.fi, y = tt.se.se;

			pll ul = norm(mp(x + R, y));
			pll ur = norm(mp(-(x - R), y));

			int angl = upper_bound(ALL(vl), ul, cmp) - vl.begin() - 1;
			int angr = upper_bound(ALL(vr), ur, cmp) - vr.begin() - 1;
			//cout << angl << " " << angr << endl;
			ang[now] = mp(angl, angr);
			add(ang[now]);
			++now;
		} else if (tt.fi == 2) {
			int id = tt.se.fi;
			del(ang[id]);
		} else {
			int p = tt.se.fi, q = tt.se.se;
			int angl = min(ang[p].fi, ang[q].fi);
			int angr = min(ang[p].se, ang[q].se);
			bool in = (vl[angl].fi * vr[angr].fi - vl[angl].se * vr[angr].se > 0LL);
			if (in) {
				puts("NO");
				continue;
			} 
			del(ang[p]);
			del(ang[q]);
			int mx = seg.get(angl, vl.size());
			if (mx >= angr) {
				puts("NO");
			} else {
				puts("YES");
			}
			add(ang[p]);
			add(ang[q]);			
		}
	}

	return 0;
}