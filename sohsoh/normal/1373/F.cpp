/*
    Soheil Mohammadkhani
    finally, i've got candidate master, so wait for the text :|
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

ll n, A[MAXN], B[MAXN], T[MAXN];

ll stat(ll mid) {
    ll ans = 0, red = mid;
    for (int i = 1; i < n; i++) {
        ll x = A[i];
        x -= B[i - 1] - red;
        red = x;
        red = max(red, 0ll);
        if (red > B[i]) return 1;
    }

    ll need = A[0] - mid;
    if (B[n - 1] - red < need) return 2;
    return 0;
}

ll solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];

    ll L = 0, R = min(A[0], B[0]);
    while (L <= R) {
        ll mid = (L + R) / 2;
        ll status = stat(mid);
        if (status == 0) return cout << "YES" << sep << endl, 0;
        else if (status == 1) R = mid - 1;
        else L = mid + 1;
    }

    cout << "NO" << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}