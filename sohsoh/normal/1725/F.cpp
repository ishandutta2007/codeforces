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
const ll LOG = 30;

int ans[LOG], n, L[MAXN], R[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> L[i] >> R[i];

	for (int t = 0; t < LOG; t++) {
		int x = (1 << t);

		vector<pll> vec;
		for (int i = 1; i <= n; i++) {
			if (R[i] - L[i] + 1 >= x) {
				vec.push_back({0, 1});
				continue;
			}

			if (R[i] % x < L[i] % x) {
				vec.push_back({0, 1});
				vec.push_back({R[i] % x + 1, -1});
				vec.push_back({L[i] % x, 1});
				vec.push_back({x, -1});
			} else {
				vec.push_back({L[i] % x, 1});
				vec.push_back({R[i] % x + 1, -1});
			}
		}

		sort(all(vec));
		int f = 0;
		for (auto [ind, x] : vec) {
			f += x;
			ans[t] = max(ans[t], f);
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		cout << ans[__builtin_ctz(x)] << endl;
	}
		
	return 0;
}