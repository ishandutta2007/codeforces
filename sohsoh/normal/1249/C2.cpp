/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Candidate Master":)
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

const ll MAXN = 5e5 + 10;
const ll INF = 8e16;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll a[70] = {0};

ll solve() {
    fill(a, a + 70, 0);
    ll n;
    cin >> n;
    ll j = 0;
    while (n > 0) {
        a[j] = n % 3;
        n /= 3;
        j++;
    }

    ll la = -1;
    for (ll i = 0; i < 70; i++) if (a[i] == 2) la = max(la, i);
    for (int i = la; la != -1; i++) {
        if (a[i] == 0) {
            for (int j = 0; j < i; j++) {
                a[j] = 0;
            }
            a[i]++;
            break;
        }
    }

    ll p = 1;
    ll ans = 0;
    for (int i = 0; i < 70; i++) {
        if (a[i]) ans += p;
        p *= 3;
    }

    cout << ans << endl;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}