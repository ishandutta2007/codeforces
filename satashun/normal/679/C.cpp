#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pii> vp;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

class unionfind {
	vector<int> par, size;

public:
	void init(int n) {
		par.resize(n);
		size.resize(n);

		for (int i = 0; i < n; i++) {
			par[i] = i;
			size[i] = 1;
		}
	}

	int find(int x) {
		if (x == -1) return x;
		if (par[x] == x) return x;
		else return par[x] = find(par[x]);
	}

	void unite(int x, int y) {
		if (x == -1 || y == -1) return ;
		x = find(x);
		y = find(y);
		if (x == y) return ;
		if (size[x] < size[y]) swap(x, y);

		par[y] = x;
		size[x] += size[y];
	}

	bool same(int x, int y) { return (find(x) == find(y)); }
	int get_size(int x) { return x == -1 ? 0 : size[find(x)]; }
} uf;

int n, K;
int ret;
char c[510][510];
int id[510][510];
int s[260010];
int m[260010];
int u[260010];

int main() {
	scanf("%d %d", &n, &K);
	rep(i, n) scanf("%s", c[i]);

	int now = 0;
	memset(id, -1, sizeof(id));
	rep(i, n) rep(j, n) if (c[i][j] == '.') id[i][j] = now++;

	uf.init(now);

	rep(i, n) {
		rep(j, n) {
			if (i + 1 < n) {
				uf.unite(id[i][j], id[i+1][j]);
			}
			if (j + 1 < n) {
				uf.unite(id[i][j], id[i][j+1]);
			}
		}
	}

	for (int i = 0; i <= n - K; ++i) {
		memset(m, 0, sizeof(m));
		memset(u, 0, sizeof(u));		
		//map<int, int> m, u;

		int sm = 0;

		rep(l, K) {
			vi cand;
			if (i) cand.pb(id[i-1][l]);
			if (i + K < n) cand.pb(id[i+K][l]);
			if (K < n) cand.pb(id[i+l][K]);

			for (int v : cand) {
				int p = uf.find(v);
				if (p == -1) continue;
				if (u[p] == 0) {
					sm += uf.get_size(p);
				}
				++u[p];				
			}
		}

		for (int j = i; j < i + K; ++j) {
			rep(k, K) {
				int p = uf.find(id[j][k]);
				if (p == -1) continue;
				if (u[p] > 0) {
					--sm;
				}
				++m[p];
			}
		}

		for (int l = 0; l <= n - K; ++l) {
			ret = max(ret, sm);
			//cout << "i=" << i << ",l=" << l << ",ret="<<sm+K*K << endl;

			vi add, dec;

			for (int j = i; j < i + K; ++j) {
				if (l) {
					dec.pb(id[j][l-1]);
				}

				add.pb(id[j][l]);
				if (l+K < n) dec.pb(id[j][l+K]);

				if (l+K+1 < n) {
					add.pb(id[j][l+K+1]);
				}
			}

			if (l + K < n) {
				if (i) add.pb(id[i-1][l+K]);
				if (i + K < n) add.pb(id[i+K][l+K]);
			}

			if (i) dec.pb(id[i-1][l]);
			if (i + K < n) dec.pb(id[i+K][l]);

			//erase
			for (int j = i; j < i + K; ++j) {
				int p = uf.find(id[j][l]);
				if (p == -1) continue;
				if (u[p] > 0) ++sm;
				--m[p];			
			}

			for (int v : dec) {
				int p = uf.find(v);
				if (p == -1) continue;

				if (--u[p] == 0) {
					sm -= uf.get_size(p);
					sm += m[p];
				}
			}

			for (int v : add) {
				int p = uf.find(v);
				if (p == -1) continue;

				if (u[p] == 0) {
					sm += uf.get_size(p);
					sm -= m[p];
				}

				++u[p];
			}

			if (l + K < n) {
				for (int j = i; j < i + K; ++j)	{
					int p = uf.find(id[j][l + K]);
					if (p == -1) continue;
					if (u[p] > 0) --sm;
					++m[p];
				}
			}

		}
	}

	printf("%d\n", ret + K * K);

	return 0;
}