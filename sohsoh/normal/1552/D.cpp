// Sohsoh84 :)))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define int			    ll

const ll MAXN = 1e5 + 10;

int n;

inline int solve() {
	set<int> st;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;

		vector<int> st2;
		for (int e : st) st2.push_back(e);
		for (int e : st2) st.insert(e - x), st.insert(e + x);

		st.insert(x);
	}

	cout << (st.find(0) == st.end() ? "NO" : "YES") << endl;
	return 0;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}