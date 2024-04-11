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

inline void solve() {
	set<string> st;
	int n;
	cin >> n;

	bool flag = false;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		st.insert(s);

		reverse(all(s));
		if (st.find(s) != st.end()) flag = true;

		if (s.size() == 3) {
			s.pop_back();
			if (st.find(s) != st.end()) flag = true;
		} else {
			for (char c = 'a'; c <= 'z'; c++) {
				if (st.find(s + c) != st.end()) flag = true;
			}
		}
	}

	if (flag) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}