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

const ll MAXN = 1e3 + 10;

int mx[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		memset(mx, 0, sizeof mx);
		int n, k;
		cin >> n >> k;

		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			mx[i % k] = max(mx[i % k], x);
		}

		ll ans = 0;
		for (int i = 0; i < k; i++)
			ans += mx[i];
		cout << ans << endl;
	}
	return 0;
}