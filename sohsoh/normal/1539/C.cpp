// \_()_/
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

ll n, k, x;
vector<ll> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k >> x;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		v.push_back(x);
	}

	sort(all(v));
	ll ans = 1;
	multiset<ll> st;

	for (int i = 1; i < n; i++) {
		if (v[i] > v[i - 1] + x) {
			ans++;
			st.insert((v[i] - v[i - 1] + x - 1) / x - 1);
		}
	}
	
	while (true) {
		if (st.empty()) break;
		ll t = *st.begin();
			
		if (k >= t) {
			k -= t;
			st.erase(st.begin());
			ans--;
		}
		
		else break;
	}

	cout << ans << endl;
	return 0;
}