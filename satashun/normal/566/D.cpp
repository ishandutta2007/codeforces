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

int n, q;
set<int> undone;

int main() {
    scanf("%d%d", &n, &q);

    uf.init(n);
    rep(i, n - 1) undone.insert(i); //i - i+1
    
    while (q--) {
	int tp, x, y;
	scanf("%d%d%d", &tp, &x, &y);
	--x; --y;

	if (tp == 1) {
	    uf.unite(x, y);
	} else if (tp == 2) {
	    auto it = undone.lower_bound(x);
	    while (it != undone.end() && *it < y) {
		uf.unite(*it, *it + 1);
		undone.erase(it++);
	    }
	} else {
	    puts(uf.same(x, y) ? "YES" : "NO");
	}
    }


    return 0;
}