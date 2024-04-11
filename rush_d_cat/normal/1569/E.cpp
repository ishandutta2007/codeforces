#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int k, a, h;
int mpow(int a, int x) {
	if (x == 0) return 1;
	int t = mpow(a, x>>1);
	if (x % 2 == 0)
		return 1ll * t * t % mod;
	return 1ll * t * t % mod * a % mod;
}
vector< pair<int,int> > bit[32];

struct B {
	map<int, vector<int> > st[33];
	void init() {
		for (int i = 0; i < 33; i ++) st[i].clear();
	}
	void build(int l, int k) {
		init();
		int n = (1<<k) - 1;
		vector<int> rk;
		for (int s = 0; s < 1<<n; s ++) {
			int sum = 0, win = 0;
			rk.clear();
			for (int i = 0; i <= n; i ++) {
				int myrk = (1<<k)+1;
				for (int j = 0; j < bit[i].size(); j ++) {
					if ((s >> (bit[i][j].first) & 1) ^ bit[i][j].second)  {
						myrk = (myrk + 1) >> 1;
					} else {
						break;
					}
				}
				sum = (sum + 1ll * (l + i) * mpow(a, myrk) % mod) % mod;
				if (myrk == 2) {
					win = l + i;
				}
				rk.emplace_back(myrk);
			}
			st[win][sum] = rk;
			//printf("s = %d, win = %d, sum = %d\n",s,  win, sum);
			//for (auto x: rk) cout << x << " "; cout << "\n";
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin >> k >> a >> h;
	int tot = 1<<(k-1);
	int id = 0;
	// cout << tot << "\n";
	for (int step = 2; step <= tot; step <<= 1) {
		for (int i = 0; i < tot; i += step) {
			for (int x = i; x < i + step; x ++) {
				bit[x].emplace_back(make_pair(id, x >= i + step / 2));
				//printf("%d %d\n", x, id);
			}
			id ++;
		}
	}
	//cout << id << "\n";
	B X, Y;
	X.build(1, k - 1);
	Y.build(1 + (1<<(k-1)), k - 1);
	
	for (int i = 1; i <= (1<<(k-1)); i ++) {
		int need = ((h + 1ll * i * a % mod * a % mod - 1ll * i * a % mod) % mod + mod) % mod;
		for (int j = (1<<(k-1)) + 1; j <= 1<<k; j ++) {
			for (auto x: X.st[i]) {
				// x + y = need
				int y = (need - x.first + mod) % mod;
				if (Y.st[j].find(y) != Y.st[j].end()) {
					vector<int> ans;
					for (auto e: x.second) {
						ans.emplace_back(e==2?1:e); 
					}
					for (auto e: Y.st[j][y]) {
						ans.emplace_back(e);
					}
					for (auto e: ans) cout << e << " "; cout << "\n";
					return 0;
				}
			}
		}
	}

	swap(X, Y);
	for (int i = (1<<(k-1)) + 1; i <= 1<<k; i ++) {
		int need = ((h + 1ll * i * a % mod * a % mod - 1ll * i * a % mod) % mod + mod) % mod;
		for (int j = 1; j <= (1<<(k-1)); j ++) {
			for (auto x: X.st[i]) {
				// x + y = need
				int y = (1ll * need - x.first + mod) % mod;
				if (Y.st[j].find(y) != Y.st[j].end()) {
					vector<int> ans;
					for (auto e: Y.st[j][y]) {
						ans.emplace_back(e);
					}
					for (auto e: x.second) {
						ans.emplace_back(e==2?1:e); 
					}
					for (auto e: ans) cout << e << " "; cout << "\n";
					return 0;
				}
			}
		}
	}
	cout << -1 << "\n";
}