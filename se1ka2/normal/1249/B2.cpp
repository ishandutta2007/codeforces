#include <iostream>
using namespace std;

class UnionFind
{
	int par[200002], rank[200002], sz[200002];

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

int main(){
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        int n;
        cin >> n;
        UnionFind uf(n);
        int p[200002];
        for(int i = 0; i < n; i++){
            cin >> p[i];
            p[i]--;
            uf.unite(i, p[i]);
        }
        for(int i = 0; i < n; i++) cout << uf.size(i) << " ";
        cout << endl;
    }
}