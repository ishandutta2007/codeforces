#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

#ifdef LOCAL
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else 
#define dump(x) true
#endif

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

const int maxn = 300010;

V<int> sw[maxn];

int col[maxn];
int mt[maxn];

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
		if (par[x] == x) return x;
		else return par[x] = find(par[x]);
	}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return ;
		if (size[x] < size[y]) swap(x, y);

		par[y] = x;
		if (col[y] != -1) {
			col[x] = col[y];
		}
		if (mt[y] != -1 && mt[x] == -1) {
			mt[x] = mt[y];
		}
		size[x] += size[y];
	}

	bool same(int x, int y) { return (find(x) == find(y)); }
	int get_size(int x) { return size[find(x)]; }

};

int main() {
	int n, k; cin >> n >> k;
	string s; cin >> s;

	rep(i, k) {
		int num; scanf("%d", &num);
		rep(j, num) {
			int x; scanf("%d", &x);
			--x;
			sw[x].pb(i);
		}
	}

	unionfind uf;
	uf.init(k);

	memset(col, -1, sizeof(col));
	memset(mt, -1, sizeof(mt));

	auto get = [&](int v) {
		int a = uf.find(v);
		dump(mp(a,col[a]));
		if (col[a] != -1) {
			if (col[a] == 1) {
				return uf.get_size(a);
			} else {
				int num = 0;
				if (mt[a] != -1) {
					num = uf.get_size(mt[a]);
					dump(num);
				}
				return num;
			}
		} else if (mt[a] != -1 && col[uf.find(mt[a])] != -1) {
			if (col[uf.find(mt[a])] == 1) {
				return uf.get_size(mt[a]);
			} else {
				return uf.get_size(a);
			}
		} else {
			int k = uf.get_size(a);
			if (mt[a] != -1) {
				chmin(k, uf.get_size(mt[a]));
			} else {
				k = 0;
			}
			return k;
		}
	};

	int ans = 0;

	rep(i, n) {
		bool f = (s[i] == '0');
		if (sw[i].size() == 2) {
			dump(i);

			if (!f) {
				int a = uf.find(sw[i][0]), b = uf.find(sw[i][1]);
				if (uf.same(a, b)) {
					printf("%d\n", ans);
					continue;
				}
				ans -= get(a);
				ans -= get(b);

				if (mt[a] != -1 && mt[b] != -1) {
					uf.unite(mt[a], mt[b]);
				}
				uf.unite(sw[i][0], sw[i][1]);

				dump(get(a));
				ans += get(sw[i][0]);
				dump(uf.get_size(a));
				if (mt[a] != -1) {
					dump(uf.get_size(mt[a]));
				}
			} else {
				int a = uf.find(sw[i][0]), b = uf.find(sw[i][1]);

				if (mt[a] != -1  && uf.find(mt[a]) == b) {
					printf("%d\n", ans);
					continue;
				}

				ans -= get(sw[i][0]);
				ans -= get(sw[i][1]);

				if (mt[a] == -1) {
					mt[a] = b;
				}	
				if (mt[b] == -1) {
					mt[b] = a;
				}
				uf.unite(a, mt[b]);
				uf.unite(b, mt[a]);
				dump(get(a));
				ans += get(a);
			}
		} else if (sw[i].size() == 1) {
			dump(i);
			ans -= get(sw[i][0]);
			dump(ans);
			col[uf.find(sw[i][0])] = f;
			dump(get(sw[i][0]));
			ans += get(sw[i][0]);
		}
		printf("%d\n", ans);
	}

	return 0;
}