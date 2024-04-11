#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back
#define fir first
#define sec second

const int N = 2e5L + 233;
int lb(int x) { return x & (-x); }
struct BIT {
	int b[N];
	void change(int p, int x) {
		p += 4;
		for(; p < N; p += lb(p))
			b[p] += x;
	}
	int query(int p) {
		p += 4; int r = 0;
		for(; p; p -= lb(p))
			r += b[p];
		return r;
	}
}bit;

struct eve {
	int x, y;
	int t, qi, qj, sgn;
	bool operator <(eve e) {
		return tie(x, t) < tie(e.x, e.t);
	}
};

ll c[N][10];
int p[N];

int main() {
	int n, q; cin >> n >> q;
	vector <eve> v;
	for(int i = 1; i <= n; i ++) {
		scanf("%d", p + i);
		v.pb({i, p[i], 0, 0, 0, 0});
	}
	
	for(int i = 1; i <= q; i ++) {
		int l, d, r, u;
		scanf("%d%d%d%d", &l, &d, &r, &u);
		v.pb({r, u, 1, i, 0, 1});
		v.pb({l - 1, u, 1, i, 0, -1});
		v.pb({r, d - 1, 1, i, 0, -1});
		v.pb({l - 1, d - 1, 1, i, 0, 1});
		
		v.pb({r, u, 1, i, 1, 1});
		
		v.pb({r, n, 1, i, 2, 1});
		v.pb({r, d - 1, 1, i, 2, -1});
		
		v.pb({n, n, 1, i, 3, 1});
		v.pb({l - 1, n, 1, i, 3, -1});
		v.pb({n, d - 1, 1, i, 3, -1});
		v.pb({l - 1, d - 1, 1, i, 3, 1});
		
		v.pb({n, u, 1, i, 4, 1});
		v.pb({l - 1, u, 1, i, 4, -1});
		
		v.pb({r, u, 1, i, 5, 1});
		v.pb({r, d - 1, 1, i, 5, -1});
		
		v.pb({r, n, 1, i, 6, 1});
		v.pb({l - 1, n, 1, i, 6, -1});
		v.pb({r, d - 1, 1, i, 6, -1});
		v.pb({l - 1, d - 1, 1, i, 6, 1});
		
		v.pb({n, u, 1, i, 7, 1});
		v.pb({l - 1, u, 1, i, 7, -1});
		v.pb({n, d - 1, 1, i, 7, -1});
		v.pb({l - 1, d - 1, 1, i, 7, 1});
		
		v.pb({r, u, 1, i, 8, 1});
		v.pb({l - 1, u, 1, i, 8, -1});
		
		//cout << l - 1 << ' ' << u << '\n';
	}
	
	sort(v.begin(), v.end());
	for(eve e : v) {
		if(e.t == 0)
			bit.change(e.y, 1);
		else {
			c[e.qi][e.qj] += e.sgn * bit.query(e.y);
			//if(e.qi == 1 && e.qj == 4)
				//cout << bit.query(e.y) << '\n';
		}
	}
	
	//cout << bit.query(n) << '\n';
	
	for(int i = 1; i <= q; i ++) {
		ll ans = 0;
		for(int j = 1; j <= 8; j ++)
			c[i][j] -= c[i][0];
		//for(int j = 0; j <= 4; j ++)
			//cout << c[i][j] << ' '; cout << '\n';
		ans += c[i][0] * (n - c[i][0]);
		ans += c[i][0] * (c[i][0] - 1) / 2;
		ans += c[i][1] * c[i][3];
		ans += c[i][2] * c[i][4];
		
		ans -= c[i][5] * c[i][7];
		ans -= c[i][6] * c[i][8];
		printf("%lld\n", ans);
	}
	
	return 0;
}