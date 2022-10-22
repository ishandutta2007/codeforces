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

vector<int> v;

inline bool check(int e) {
	vector<int> t;
	for (int x : v)
		if (x != e)
			t.push_back(x);
	vector<int> r = t;
	reverse(all(r));
	return r == t;
}

inline int solve() {
	v.clear();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	if (check(MAXN)) return cout << "YES" << endl, 0; 
	
	for (int i = 0; i < n; i++) {
		if (v[i] != v[n - 1 - i]) {
			if (check(v[i]) || check(v[n - 1 - i])) return cout << "YES" << endl, 0;
			cout << "NO" << endl;
			return 0;
		} 
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}