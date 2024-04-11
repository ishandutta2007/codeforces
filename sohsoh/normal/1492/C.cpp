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

int m, n, ind1[MAXN], ind2[MAXN];
string s, t;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> s >> t;
	int pt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (pt < t.size() && s[i] == t[pt]) pt++;
		ind1[i] = pt;
	}

	pt = m - 1;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (pt >= 0 && s[i] == t[pt]) pt--;
		ind2[i] = pt + 1;
	}

	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (ind1[i] != 0 && ind1[i] != n) {
			int ind = lower_bound(ind2, ind2 + n, ind1[i] + 1) - ind2 - 1;
			ans = max(ans, ind - i);
		}
	}

	cout << ans << endl;
	return 0;
}