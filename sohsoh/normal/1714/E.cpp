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
	int n;
	cin >> n;
	set<int> st;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		x = x + x % 10;

		if (x % 10 == 0) st.insert(x);
		else {
			x /= 2;
			if (x % 10 == 1 || x % 10 == 2 || x % 10 == 4 || x % 10 == 8) st.insert(-1);
			else st.insert(-2);
		}
	}

	cout << (st.size() < 2 ? "Yes" : "No") << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}