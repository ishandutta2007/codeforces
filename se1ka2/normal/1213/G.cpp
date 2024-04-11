#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll ans[200005] {0};
vector<P> g[200005];

class UnionFind
{
	ll par[200002], rank[200002], sz[200002];

public:
	UnionFind(int n) {
		for (int i = 0; i < n; i++) {
			par[i] = i;
			rank[i] = 0;
			sz[i] = 1;
		}
	}

	ll find(int x) {
		if (x == par[x]) return x;
		else return par[x] = find(par[x]);
	}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (rank[x] < rank[y]) {
			par[x] = y;
			sz[y] += sz[x];
		}
		else {
			par[y] = x;
			sz[x] += sz[y];
			if (rank[x] == rank[y]) rank[x]++;
		}
	}

	ll size(ll x) {
		return sz[find(x)];
	}
    
	bool same(ll x, ll y) {
        return find(x) == find(y);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n - 1; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--;
        v--;
        g[w].push_back(P(u, v));
    }
    UnionFind uf(n);
    for(int i = 1; i <= 200000; i++){
        ans[i] += ans[i - 1];
        for(P p : g[i]){
            ll l = p.first, r = p.second;
            ans[i] += uf.size(l) * uf.size(r);
            uf.unite(l, r);
        }
    }
    for(int i = 0; i < m; i++){
        int q;
        cin >> q;
        printf("%lld ", ans[q]);
    }
    cout << endl;
}