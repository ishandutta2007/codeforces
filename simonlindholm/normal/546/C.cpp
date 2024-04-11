#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool seen(vi& a, vi& b) {
	ll r = 0;
#define ADD(x) r *= 10, r += x
	ADD(sz(a)-1);
	trav(x, a) ADD(x);
	trav(x, b) ADD(x);
	static set<ll> smap;
	if (smap.count(r)) return true;
	smap.insert(r);
	return false;
}

int main() {
	int N, k1, k2;
	cin >> N;
	cin >> k1; vi p1(k1); trav(x, p1) cin >> x;
	cin >> k2; vi p2(k2); trav(x, p2) cin >> x;
	int turns = 0;
	while (!p1.empty() && !p2.empty()) {
		++turns;
		if (seen(p1, p2)) {
			cout << -1 << endl;
			return 0;
		}
		int c1 = p1.front(); p1.erase(p1.begin());
		int c2 = p2.front(); p2.erase(p2.begin());
		if (c1 > c2) { p1.push_back(c2); p1.push_back(c1); }
		else         { p2.push_back(c1); p2.push_back(c2); }
	}
	cout << turns << ' ' << (p1.empty() ? 2 : 1) << endl;
}