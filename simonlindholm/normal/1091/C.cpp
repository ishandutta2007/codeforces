#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	ll N;
	cin >> N;
	set<ll> res;
	vector<ll> divs;
	for (int d = 1; d <= N; d++) {
		if (d*d > N) break;
		if (N % d == 0) {
			divs.push_back(d);
			ll d2 = N/d;
			if (d2 != d)
			divs.push_back(d2);
		}
	}
	trav(d, divs) {
		ll r = N/d;
		ll re = r + d * (r * (r-1) / 2);
		res.insert(re);
	}
	trav(x, res) cout << x << ' ';
	cout << endl;
	exit(0);
}