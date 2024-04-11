#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod = 998244353;
const int N = 1000000 + 10;
ll pw[N];
struct {
	int s[N][2];
	int c[3];
	void add(int x, int y, int z, int sgn) {
		c[not s[x][0] + not s[x][1]] --;
		s[x][(y ^ z) & 1] += sgn;
		c[not s[x][0] + not s[x][1]] ++;
	}
	ll query() {
		return c[0]?0:pw[c[2]];
	}
	void init(int n) {
		c[2] = n;
	}
	void p() {
		printf("%d %d %d\n", c[0],c[1],c[2]);
	}
} R, C;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	map<pair<int,int>,int > mp;
	R.init(n), C.init(m);

	pw[0] = 1;
	for (int i = 1; i < N; i ++)
		pw[i] = pw[i-1] * 2 % mod;

	int c[2] = {};
	for (int i = 0; i < k; i ++) {
		int x, y, t;
		cin >> x >> y >> t;
		auto it = mp.find({x, y});		
		if (it != mp.end()) {
			int val = it->second;
			mp.erase(it);
			c[(x^y^val) & 1] --;
			R.add(x, y, val, -1);
			C.add(y, x, val, -1);
		}
		if (t >= 0) {
			mp[{x, y}] = t;
			c[(x^y^t) & 1] ++;
			R.add(x, y, t, +1);
			C.add(y, x, t, +1);
		}
		ll ans = R.query() + C.query() - not c[0] - not c[1];
		ans = (ans % mod + mod) % mod;
		cout << ans << "\n";
	}
}