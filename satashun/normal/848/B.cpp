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

int n, w, h;
vector<pii> vec;
vector<pair<int, pii>> pt;

int main() {
	scanf("%d %d %d", &n, &w, &h);

	rep(i, n) {
		int g, p, t;
		scanf("%d %d %d", &g, &p, &t);
		vec.eb(p - t, i);
		pt.eb(g, mp(p, t));
	}

	sort(ALL(vec));
	vector<pii> ans(n);

	for (int i = 0; i < n; ) {
		int j = i;
		while (j < n && vec[j].fi == vec[i].fi) ++j;

		vector<pair<pii, int>> vv;
		vector<pii> gl;

		for (int k = i; k < j; ++k) {
			int id = vec[k].se;
			if (pt[id].fi == 2) {
				vv.eb(mp(0, -pt[id].se.fi), id);
				gl.eb(w, -pt[id].se.fi);
			} else {
				vv.eb(mp(pt[id].se.fi, 0), id);
				gl.eb(pt[id].se.fi, h);
			}
		}

		sort(ALL(vv));
		sort(ALL(gl));

		rep(k, vv.size()) {
			int id = vv[k].se;
			ans[id] = gl[k];
		}

		i = j;
	}

	rep(i, n) {
		printf("%d %d\n", abs(ans[i].fi), abs(ans[i].se));
	}

	return 0;
}