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

ll A[MAXN], n, k, z;

ll solve() {
    cin >> n >> k >> z;
    for (int i = 0; i < n; i++) cin >> A[i];
    ll ps = A[0];

    ll mx_pair = 0;
    ll fans = 0;
    for (int i = 1; i < n; i++) {
        ps += A[i];
        mx_pair = max(mx_pair, A[i - 1] + A[i]);
        ll mv = k - i;
        ll ans = ps;
        if (mv < 0) continue;
        if ((mv + 1) / 2 > z) continue;
        ans += (mv / 2) * mx_pair;
        if (mv & 1) ans += A[i - 1];
        if (ans == 63) debug(i)
        fans = max(fans, ans);
    }

    cout << fans << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}