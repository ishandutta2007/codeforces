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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

int n, q;
set<pll> st, st2;
map<pll, char> mp;

inline pll F(int u, int v) {
	if (u > v) swap(u, v);
	return {u, v};
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	while (q--) {
		char c;
		cin >> c;

		if (c == '+') {
			int u, v;
			cin >> u >> v >> c;
			mp[make_pair(u, v)] = c;
			auto it = mp.find(make_pair(v, u));
			if (it != mp.end()) {
				st.insert(F(v, u));
				if (it -> Y == c) st2.insert(F(v, u));
			}
		} else if (c == '-') {
			int u, v;
			cin >> u >> v;
			mp.erase({u, v});
			st.erase(F(u, v));
			st2.erase(F(u, v));
		} else {
			int k;
			cin >> k;
			if (k & 1) {
				if (st.empty()) cout << "NO" << endl;
				else cout << "YES" << endl;
			} else {
				if (st2.empty()) cout << "NO" << endl;
				else cout << "YES" << endl;
			}
		}
	}
	return 0;
}