#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
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

vector<pair<pll, int>> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		v.clear();
		int n;
		cin >> n;
		n = n * 2 - 1;
		v.resize(n);
		for (int i = 0; i < n; i++) cin >> v[i].X.X >> v[i].X.Y, v[i].Y = i + 1;
		sort(all(v), greater<pair<pll, int>>());
		vector<int> ans = {v.front().Y};
		for (int i = 1; i < n; i += 2) {
			if (v[i].X.Y < v[i + 1].X.Y) ans.push_back(v[i + 1].Y);
			else ans.push_back(v[i].Y);
		}

		sort(all(ans));
		cout << "YES" << endl;
		for (int e : ans) cout << e << sep;
		cout << endl;
	}
	return 0;
}