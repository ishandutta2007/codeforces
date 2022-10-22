/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Expert" :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

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

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN], a[MAXN], n;

int main() {
    fast_io;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i] = 1;
    }

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < a[i + 1]) dp[i] = max(dp[i], dp[i + 1] + 1);
    }

    for (int i = 1; i < n; i++) if (a[i] > a[i - 1]) dp[i] = dp[i - 1];
//    alog(dp, n);

    ll ans = *max_element(dp, dp + n);
    for (int i = 1; i < n - 1; i++) {
        if (a[i + 1] <= a[i - 1] || (a[i - 1] < a[i] && a[i] < a[i + 1])) continue;
        ans = max(ans, dp[i - 1] + dp[i + 1] - 1);
    }

    cout << ans << endl;
    return 0;
}