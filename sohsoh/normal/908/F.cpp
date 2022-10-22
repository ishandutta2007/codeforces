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

vector<pll> P;
vector<int> GR, GB;
ll ans = 0, n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		char c;
		cin >> x >> c;
		if (c == 'G') {
			GR.push_back(x);
			GB.push_back(x);
			P.push_back({x, 0});
		} else if (c == 'R') {
			GR.push_back(x);
			P.push_back({x, 1});
		} else {
			GB.push_back(x);
			P.push_back({x, 2});
		}
	}

	sort(all(GB));
	sort(all(GR));
	sort(all(P));
	if (!GB.empty()) ans += GB.back() - GB.front();
	if (!GR.empty()) ans += GR.back() - GR.front();

	int last_g = 0, b_r = 0, b_b = 0, last_gr = 0, last_gb = 0;
	for (int i = 0; i < n; i++) {
		int c = P[i].Y, x = P[i].X;
		if ((c == 0 || c == 1)) {
			if (last_gr > 0) b_r = max(b_r, x - last_gr);
			last_gr = x;
		}

		if ((c == 0 || c == 2)) {
			if (last_gb > 0) b_b = max(b_b, x - last_gb);
			last_gb = x;
		}

		if (c == 0) {
			if (last_g)
				if (x - last_g < b_b + b_r)
					ans += x - last_g - b_b - b_r;

			b_r = 0;
			b_b = 0;
			last_g = x;
		}
	}

	cout << ans << endl;
	return 0;
}