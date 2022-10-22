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

ld a, b, c, d;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> a >> b >> c >> d;
	
	ld L = 0, R = 1e9;
	int step = 10000;
	while (step-- && L < R) {
		ld mid = (L + R) / ld(2);
		ld mn_a = a - mid, mx_a = a + mid, mn_b = b - mid, mx_b = b + mid, mn_c = c - mid, mx_c = c + mid, mn_d = d - mid, mx_d = d + mid;
		ld mn_1 = min({mn_a * mn_d, mn_a * mx_d, mx_a * mn_d, mx_a * mx_d});
		ld mx_1 = max({mn_a * mn_d, mn_a * mx_d, mx_a * mn_d, mx_a * mx_d});
		ld mn_2 = min({mn_b * mn_c, mn_b * mx_c, mx_b * mn_c, mx_b * mx_c});
		ld mx_2 = max({mn_b * mn_c, mn_b * mx_c, mx_b * mn_c, mx_b * mx_c});
		
		if (max(mn_1, mn_2) <= min(mx_1, mx_2)) R = mid;
		else L = mid;
	}

	cout << setprecision(10) << fixed << endl;
	cout << L << endl;
	return 0;
}