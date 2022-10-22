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
	ll o = 0, tw = 0, th = 0, ans = 0;
	ll n;
	cin >> n;
	while (n--) {
		ll x;
		cin >> x;
		if (x == 4) ans++;
		else if (x == 3) th++;
		else if (x == 2) tw++;
		else o++;
	}

	while (th > 0) {
		if (o > 0) o--, th--;
		else th--;
		ans++;
	}

	while (tw > 0) {
		if (tw > 1) tw--;
		else if (o > 1) o -= 2;
		else if (o > 0) o -= 1;
		tw--;
		ans++;
	}
	
	ans += ll(ceil(ld(o) / 4));
	cout << ans << endl;
	return 0;
}