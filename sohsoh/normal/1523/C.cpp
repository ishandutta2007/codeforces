#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define endl 			    '\n'

const ll MAXN = 1e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n;

void print(vector<int> t) {
	cout << t[0];
	for (int i = 1; i < t.size(); i++) cout << '.' << t[i];
	cout << endl;
}

inline int solve() {
	stack<vector<int>> st;
	cin >> n;
	int t;
	cin >> t;
	st.push({1});

	cout << 1 << endl;
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		if (x == 1) {
			st.push(st.top());
			st.top().push_back(1);
		} else {
			while (st.top().back() != x - 1)
				st.pop();
			vector<int> v = st.top();
			st.pop();
			st.push(v);
			st.top().back()++;
		}

		print(st.top());
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}