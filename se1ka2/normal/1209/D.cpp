#include <iostream>
using namespace std;

class UnionFind
{
	int par[100002], rank[100002], sz[100002];

public:
	UnionFind(int n) {
		for (int i = 0; i < n; i++) {
			par[i] = i;
			rank[i] = 0;
			sz[i] = 1;
		}
	}

	int find(int x) {
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

	int size(int x) {
		if (x == par[x]) return sz[x];
		else return sz[x] = sz[find(x)];
	}
    
	bool same(int x, int y) {
        return find(x) == find(y);
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    int x[100002], y[100002];
    UnionFind uf(n);
    for(int i = 0; i < k; i++){
        cin >> x[i] >> y[i];
        uf.unite(x[i], y[i]);
    }
    int h = 0;
    for(int i = 0; i < n; i++){
        if(uf.find(i) == i) h += uf.size(i) - 1;
    }
    cout << k - h << endl;
}