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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN];

ll solve() {
    ll h, n, last = 0;
    cin >> h >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && A[i - 1] - 1 != A[i]) {
            if (last != 0 && (i - last) % 2) ans++;
            if (last == 0 && (i - last) % 2 == 0) ans++;
            last = i;
        }
    }

    if (A[n - 1] > 1) {
        if (last != 0 && (n - last) % 2) ans++;
        if (last == 0 && (n - last) % 2 == 0) ans++;
    }

    cout << ans << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}