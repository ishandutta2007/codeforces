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

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;	
		set<int> st;
		for (int i = 1; i <= n; i++) cin >> A[i], st.insert(i);
		vector<int> ans, t;
		for (int i = n; i >= 1; i--) {
			t.push_back(A[i]);
			if (A[i] == *st.rbegin()) {
				reverse(all(t));
				for (int e : t) ans.push_back(e);
				t.clear();
			}

			st.erase(A[i]);
		}

		for (int e : ans) cout << e << sep;
		cout << endl;
	}
	return 0;
}