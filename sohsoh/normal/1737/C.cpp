#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<pll> vec;
		for (int i = 0; i < 3; i++) {
			int a, b;
			cin >> a >> b;
			vec.push_back(pll(a, b));
		}

		pll e;
		cin >> e.X >> e.Y;

		sort(all(vec));
		vector<pll> tvec = {pll(1, 1), pll(1, 2), pll(2, 1)};
		sort(all(tvec));
		if (tvec == vec && (e.X != 1 && e.Y != 1)) {
			cout << "NO" << endl;
			continue;
		}

		sort(all(vec));
		tvec = {pll(1, n), pll(2, n), pll(1, n - 1)};
		sort(all(tvec));
		if (tvec == vec && (e.X != 1 && e.Y != n)) {
			cout << "NO" << endl;
			continue;
		}

		sort(all(vec));
		tvec = {pll(n, 1), pll(n - 1, 1), pll(n, 2)};
		sort(all(tvec));
		if (tvec == vec && (e.X != n && e.Y != 1)) {
			cout << "NO" << endl;
			continue;
		}

		sort(all(vec));
		tvec = {pll(n, n), pll(n - 1, n), pll(n, n - 1)};
		sort(all(tvec));
		if (tvec == vec && (e.X != n && e.Y != n)) {
			cout << "NO" << endl;
			continue;
		}

		for (pll& e : vec)
			e.X %= 2, e.Y %= 2;
		e.X %= 2;
		e.Y %= 2;
		cout << (find(all(vec), e) == vec.end() ? "NO" : "YES") << endl;
	}
	return 0;
}