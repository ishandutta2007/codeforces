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

int get(int x, int d) {
	return (x + d - 1) / d;
}

int n, m, c1, c2, q, v;
vi v1, v2;

int main() {
	cin >> n >> m >> c1 >> c2 >> v;
	rep(i, c1) {
		int x; cin >> x;
		--x;
		v1.pb(x);
	}
	rep(i, c2) {
		int x; cin >> x;
		--x;
		v2.pb(x);
	}
	cin >> q;

	rep(i, q) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		--a; --b; --c; --d;
		int ans = INT_MAX;

		if (a > c) swap(a, c);
		if (b > d) swap(b, d);

		if (a == c) {
			ans = d - b;
		} else {
			auto it = lower_bound(ALL(v1), b);
			if (it != v1.end()) {
				int t = c - a + abs(*it - b) + abs(*it - d);
				ans = min(ans, t);
			}
			if (it != v1.begin()) {
				--it;
				int t = c - a + abs(*it - b) + abs(*it - d);
				ans = min(ans, t);			
			}

			it = lower_bound(ALL(v2), b);
			if (it != v2.end()) {
				int t = get(c - a, v) + abs(*it - b) + abs(*it - d);
				ans = min(ans, t);
			}
			if (it != v2.begin()) {
				--it;
				int t = get(c - a, v) + abs(*it - b) + abs(*it - d);
				ans = min(ans, t);			
			}
		}
		cout << ans << "\n";
	}

	return 0;
}