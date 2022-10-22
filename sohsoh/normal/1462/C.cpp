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

int ans[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<int> v;
	for (int i = 1; i < 10; i++) v.push_back(i);
	do {
		int s = 0, x = 0;
		for (int i = 0; i < 9; i++) {
			s += v[i];
			x *= 10;
			x += v[i];
			if (ans[s] == 0) ans[s] = x;
			ans[s] = min(ans[s], x);
		}	
	} while (next_permutation(all(v)));

	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		if (ans[n] == 0) ans[n] = -1;
		cout << ans[n] << endl;
	}
	return 0;
}