#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

vector<pair<ld, ld>> intersec(ll x, ll y, ll a, ll b, ll c) {
	vector<pair<ld, ld>> res;
	if (a) {
		res.push_back(make_pair((-c - b * y + 0.0) / (a + 0.0), y));
	}
	if (b) {
		res.push_back(make_pair(x, (-c - a * x + 0.0) / (b + 0.0)));
	}
	return res;
}

ld dist(ld x1, ld y1, ld x2, ld y2) {
	ld x = x1 - x2;
	ld y = y1 - y2;
	return sqrtl(x * x + y * y);
}

void solve() {
	ll a, b, c;
	ll ax, ay, bx, by;
	cin >> a >> b >> c;
	cin >> ax >> ay >> bx >> by;

	ld ans = abs(ax - bx) + abs(ay - by);

	vector<pair<ld, ld>> ia, ib;

	ia = intersec(ax, ay, a, b, c);
	ib = intersec(bx, by, a, b, c);

	for (auto aa : ia) {
		for (auto bb : ib) {
			ans = min(ans, dist(ax, ay, aa.first, aa.second) + 
						   dist(aa.first, aa.second, bb.first, bb.second) + 
						   dist(bb.first, bb.second, bx, by));
		}
	}

	cout << fixed << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(15);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 3;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}