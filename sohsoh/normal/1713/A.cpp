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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int min_x = 0, max_x = 0, min_y = 0, max_y = 0, n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int x, y;
			cin >> x >> y;

			min_x = min(min_x, x);
			max_x = max(max_x, x);
			min_y = min(min_y, y);
			max_y = max(max_y, y);
		}

		cout << 2 * (-min_x + max_x - min_y + max_y) << endl;
	}
	return 0;
}