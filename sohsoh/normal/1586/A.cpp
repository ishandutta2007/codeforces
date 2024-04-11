//: // ////: ///  / : //// / :
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

bool is_prime(int n) {
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

inline int solve() {
	int n;
	cin >> n;
	vector<int> ev, od;

	int s = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		s += x;

		if (x & 1) od.push_back(i);
		else ev.push_back(i);
	}

	if (!is_prime(s)) {
		cout << n << endl;
		for (int i = 1; i <= n; i++) cout << i << sep;
		cout << endl;
		return 0;
	}

	od.pop_back();
	cout << n - 1 << endl;
	for (int e : ev) cout << e << sep;
	for (int e : od) cout << e << sep;
	cout << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}