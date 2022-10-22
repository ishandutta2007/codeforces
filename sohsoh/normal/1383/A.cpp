/*
    Soheil Mohammadkhani
    div1 shodam, khoshhalam nane, ishala div1, ghesmat hame :)
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
#define SZ(x)                       ll(x.size())
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
    ll n;
    string a, b;
    cin >> n >> a >> b;

    ll ans = 0;

    for (int c = 't'; c >= 'a'; c--) {
        char mx = 10;
        for (int i = 0; i < n; i++) {
            if (b[i] < a[i]) return cout << -1 << endl, 0;
            if (b[i] == c && b[i] > a[i]) {
                mx = max(mx, a[i]);
            }
        }

        if (mx == 10) continue;

        for (int i = 0; i < n; i++) {
            if (b[i] == c && b[i] > a[i]) {
                mx = max(mx, a[i]);
                b[i] = mx;
            }
        }

        ans++;
    }

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