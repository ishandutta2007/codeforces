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

int n, ans;
multiset<int> st;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	ans = n;
	ll h = 0;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		h += x;
		if (x < 0) st.insert(x);
		
		while (h < 0) {
			ans--;
			h -= *st.begin();
			st.erase(st.begin());
		}
	}

	cout << ans << endl;
	return 0;
}