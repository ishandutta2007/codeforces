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
const ll INF = 1e15;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

string s;
ll nb, ns, nc, pb, ps, pc, rb, rs, rc, r = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s >> nb >> ns >> nc >> pb >> ps >> pc >> r;
	for (char c : s) {
		if (c == 'B') rb++;
		if (c == 'S') rs++;
		if (c == 'C') rc++;
	}

	ll L = 0, R = INF;
	while (L < R) {
		ll mid = (L + R + 1) / 2;
		ll cost = max(0ll, pb * (rb * mid - nb)) + max(0ll, ps * (rs * mid - ns)) + max(0ll, pc * (rc * mid - nc));
		if (cost > r) R = mid - 1;
		else L = mid;
	}

	cout << L << endl;
	return 0;
}