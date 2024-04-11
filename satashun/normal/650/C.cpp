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

class unionfind {
    vector<int> par, rank;

    public:
    void init(int n) {
	par.resize(n);
	rank.resize(n);

	for (int i = 0; i < n; i++) {
	    par[i] = i;
	    rank[i] = 0;
	}
    }

    int find(int x) {
	if (par[x] == x) return x;
	else return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return ;

	if (rank[x] < rank[y]) par[x] = y;
	else {
	    par[y] = x;
	    if (rank[x] == rank[y]) ++rank[x];
	}
    }

    bool same(int x, int y) { return (find(x) == find(y)); }
} uf;

int n, m;
vi xs;
int ct[1000010], cy[1000010];
int mm[1000010];

int main() {
    scanf("%d %d", &n, &m);

    vector<vi> mat(n, vi(m));
    vector<vi> res(n, vi(m));

    vector<pair<int, pii> > vt;
    rep(i, n) rep(j, m) {
	scanf("%d", &mat[i][j]);
	vt.pb(mp(mat[i][j], mp(i, j)));
    }

    sort(ALL(vt));
    uf.init(n * m);
    
    for (int i = 0; i < vt.size(); ) {
	int j = i;
	int num = vt[i].fi;
	vector<pii> vp;

	while (j < vt.size() && vt[j].fi == num) {
	    vp.pb(vt[j].se);
	    ++j;
	}

	for (int k = i; k < j; ++k) {
	    pii pt = vt[k].se;
	    int x = pt.fi, y = pt.se;
	    int p = uf.find(x * m + y);
	    mm[p] = max({mm[p], ct[x], cy[y]});
	}

	sort(ALL(vp));

	for (int k = 0; k < j - i - 1; ++k) {
	    if (vp[k].fi == vp[k + 1].fi) {
		int x = vp[k].fi;
		int p = uf.find(x * m + vp[k].se);
		int p2 = uf.find(x * m + vp[k + 1].se);
		int ma = max(mm[p], mm[p2]);

		ma = max(ma, ct[x]);
		ma = max(ma, ct[x]);
		ma = max(ma, cy[vp[k].se]);
		ma = max(ma, cy[vp[k + 1].se]);
		mm[p] = mm[p2] = ma;

		uf.unite(p, p2);
	    }
	}

	rep(k, j - i) swap(vp[k].fi, vp[k].se);
	sort(ALL(vp));

	for (int k = 0; k < j - i - 1; ++k) {
	    if (vp[k].fi == vp[k + 1].fi) {
		int x = vp[k].fi;

		int p = uf.find(vp[k].se * m + x);
		int p2 = uf.find(vp[k + 1].se * m + x);
		int ma = max(mm[p], mm[p2]);

		ma = max(ma, cy[x]);
		ma = max(ma, cy[x]);
		ma = max(ma, ct[vp[k].se]);
		ma = max(ma, ct[vp[k + 1].se]);
		mm[p] = mm[p2] = ma;

		uf.unite(p, p2);
	    }
	}

	for (int k = i; k < j; ++k) {
	    pii pt = vt[k].se;
	    int x = pt.fi, y = pt.se;

	    int nc = mm[uf.find(x * m + y)] + 1;
	    res[x][y] = nc;

	    ct[x] = max(ct[x], nc);
	    cy[y] = max(cy[y], nc);
	}

	i = j;
    }

    rep(i, n) rep(j, m) printf("%d%c", res[i][j], j == m - 1 ? '\n' : ' ');

    return 0;
}