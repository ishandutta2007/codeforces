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

inline int solve() {
	ll s = 0, n, m;
	vector<int> vec;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		vec.push_back(x);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		s += x;
	}

	cout << vec[s % n] << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}