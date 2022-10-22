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
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		set<pll> st;
		int n, m, x;
		cin >> n >> m >> x;
		cout << "YES" << endl;
		for (int i = 0; i < m; i++) st.insert({0, i + 1});
		while (n--) {
			int r;
			cin >> r;
			pll e = *st.begin();
			st.erase(st.begin());
			cout << e.Y << sep;
			e.X += r;
			st.insert(e);
		}

		cout << endl;
	}
	return 0;
}