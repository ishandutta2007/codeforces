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
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll cnt = 0, n, x, y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	char p = '1';
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != p) {
			if (p == '0') cnt++;
			p = s[i];
		}
	}

	if (s.back() == '0') cnt++;
	ll ans = INF;
	ll a = 0;
	while (cnt > 0) {
		ans = min(a + cnt * y, ans);
		cnt--;
		a += x;
	}

	if (ans == INF) ans = 0;
	cout << ans << endl;
	return 0;
}