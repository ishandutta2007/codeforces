#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct dsu {
	vector<int> par;
	void init(int n) {
		par.resize(n + 1, 0);
		for (int i = 1; i <= n; i ++) par[i] = i;
	}
	int find(int x) {
		return par[x] == x ? x :par[x] = find(par[x]);
	}
	void uinite(int x, int y) {
		par[find(x)] = find(y);
	}
} D;

const int N = 1000000 + 10;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i ++) cin >> a[i];
	D.init(N);

	vector<int> mn(N, 0);
	vector<int> isp(N, 0);
	for (int i = 2; i < N; i ++) {
		if (isp[i] == 0) {
			for (int j = i; j < N; j += i) {
				if (mn[j] == 0) mn[j] = i;
			}
		}
	}
	auto fac = [&](int x) {
		int las = -1;
		while (x > 1) {
			int y = mn[x];
			if (las != -1) D.uinite(las, y);
			las = y;
			while (x % y == 0) x /= y;
		}

		if (x > 1 && las != -1) D.uinite(las, x);
	};	

	for (int i = 0; i < n; i ++) fac(a[i]);
	vector<int> id(n, 0);
	for (int i = 0; i < n; i ++) id[i] = D.find(mn[a[i]]);
 	vector< unordered_set<int> > st(N);
 	auto add = [&](int y, int x) {
	 	while (y > 1) {
 			int m = mn[y]; st[D.find(m)].insert(x);
 			while (y % m == 0) y /= m;
 		}
 		if (y > 1) st[D.find(y)].insert(x); 		
 	};
 	for (auto x: a) {
 		add(x, x);
 		add(x + 1, x);
 	}
 	
 	map< pair<int,int>, bool > ok;
 	auto solve = [&](int x, int y) {
 		bool res = false;
 		if (st[x].size() > st[y].size()) swap(x,y);
 		for (auto v1: st[x]) {
 			if (st[y].find(v1) != st[y].end())
 				res = true;
 			if (res == true) break;
 		}
 		ok[{x, y}] = ok[{y, x}] = res;
 	};

	while (q --) {
		int s, t; 
		cin >> s >> t;
		s --, t --;
		if (id[s] == id[t]) cout << 0 << endl;
		else if ((a[s] % 2 == 0) ^ (a[t] % 2 == 0)) cout << 1 << endl;
		else {
			int x = min(id[s], id[t]);
			int y = max(id[s], id[t]);
			if (ok.find({x, y}) == ok.end()) solve(x, y);
			assert(ok.find({x, y}) != ok.end());
			cout << (ok[{x, y}] ? 1: 2) << endl;	
		}
	}
}