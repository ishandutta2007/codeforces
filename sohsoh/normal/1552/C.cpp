// Sohsoh84 :)))
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

const ll MAXN = 1e5 + 10;

ll n, k;
bool vis[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 2 * n + 10; i++) vis[i] = false;
		cin >> n >> k;
		ll ans = 0;

		vector<pll> v;
		for (int i = 0 ; i < k; i++) {
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			vis[x] = vis[y] = true;

			for (pll e : v) {
				int i = e.X, j = e.Y;
				if ((x >= i && x <= j) ^ (y >= i && y <= j)) ans++;
			}

			v.push_back({min(x, y), max(x, y)});
		}

		for (pll e : v) {
			int ans1 = 0, ans2 = 0;
			for (int i = e.X + 1; i < e.Y; i++) 
				if (!vis[i])
					ans1++;
			
			int i = e.Y + 1;
			while (true) {
				i = i % (2 * n);
				if (i == e.X) break;
				if (!vis[i]) ans2++;
				i++;
			}

			ans += min(ans1, ans2);
		}

		ans += (n - k) * (n - k - 1) / 2;
		cout << ans << endl;
	}
	return 0;
}