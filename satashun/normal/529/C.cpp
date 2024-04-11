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

const int SZ = 1 << 17;

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
			dat[pos] = min(dat[pos * 2 + 1], dat[pos * 2 + 2]);
		}
	}

	int get(int a, int b, int k = 0, int l = 0, int r = SZ) {
		if (b <= l || r <= a) return 1000000;
		if (a <= l && r <= b) return dat[k];
		return min(get(a, b, k * 2 + 1, l, (l + r) / 2), get(a, b, k * 2 + 2, (l + r) / 2, r));
	}
} seg[2];

int n, m, k, q;
bool ok[200010];
int mh[200010][2];

vector<pair<pii, pii> > vec[2];

int main() {
	scanf("%d %d %d %d", &n, &m, &k, &q);

	rep(i, k) {
		int a, b;
		scanf("%d %d", &a, &b);
		--a; --b;
		vec[0].eb(mp(b, q), mp(a, 0));
		vec[1].eb(mp(a, q), mp(b, 0));
	}

	rep(i, q) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		--a; --b; --c; --d;
		vec[0].eb(mp(d+1, i), mp(a, c+1));
		vec[1].eb(mp(c+1, i), mp(b, d+1));
		mh[i][0] = b;
		mh[i][1] = a;
	}

	rep(t, 2) {
		sort(ALL(vec[t]));
		seg[t].init();

		for (auto pr : vec[t]) {
			if (pr.fi.se == q) {
				seg[t].update(pr.se.fi, pr.fi.fi);
			} else {
				int val = seg[t].get(pr.se.fi, pr.se.se);
				if (val >= mh[pr.fi.se][t]) {			
					ok[pr.fi.se] = 1;
				}
			}
		}
	}

	rep(i, q) puts(ok[i] ? "YES" : "NO");

	return 0;
}