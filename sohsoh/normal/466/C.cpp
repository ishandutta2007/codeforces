/*
    Soheil Mohammadkhani
    IDK :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9


ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

ll n, A[MAXN];
map<ll, ll> ps_sum;

int main() {
	cin >> n;
	ll s = 0;
	for (int i = 0; i < n; i++) cin >> A[i], s += A[i];
	if (s % 3) return cout << 0 << endl, 0;
	s /= 3;

	ll ps = 0, cnt = 0, ans = 0;
	for (int i = 0; i < n - 1; i++) {
		ps += A[i];
		if (ps == s) cnt++;
		if (ps != 2 * s) continue;
		ans += cnt;
		if (s == 0) ans--;
	}

	cout << ans << endl;
}