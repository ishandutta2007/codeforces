/*
    Soheil Mohammadkhani
    bullshit candidate master :|
*/
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
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll solve() {
    ll m, d, w;
    cin >> m >> d >> w;
    ll mx = min(d, m), ans = 0;
    w /= __gcd((d - 1), w);
    ll p1 = mx % w;
    if (p1 == 0) p1 = w;
    ll r = ceil(mx / ld(w));
    ans += p1 * r * (r - 1) / 2;
    p1 = (w - p1);
    r--;
    ans += p1 * r * (r - 1) / 2;
    cout << ans << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}