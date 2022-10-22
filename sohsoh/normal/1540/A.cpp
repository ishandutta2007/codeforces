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

ll D[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> v;
		for (int i = 0; i < n; i++) {
			ll x;
			cin >> x;
			v.push_back(x);
		}

		sort(all(v));
		ll s = 0, ans = 0;
		for (int i = 1; i < n; i++) {
			ans += i * v[i] - s;
			s += v[i];
		}
		
		cout << -ans + v[n - 1] << endl;
	}
	return 0;
}