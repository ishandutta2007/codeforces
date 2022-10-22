/*
    Soheil Mohammadkhani
    3 points remained to candidate master bro :)
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

const ll MAXN = 40 + 10; //Change this pls :)
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dist1[MAXN * MAXN] = {0};
ll dist2[MAXN * MAXN] = {0};

ll solve() {
    fill(dist1, dist1 + MAXN * MAXN, 0);
    fill(dist2, dist2 + MAXN * MAXN, 0);
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ll dist = i + j;
            dist = min(dist, n - i + m - j - 2);
            ll c;
            cin >> c;
            if (c) dist1[dist]++;
            else dist2[dist]++;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n * m; i++) {
        if ((n + m) % 2 == 0 && i == (n - 1 + m - 1) / 2) continue;
        ans  += min(dist1[i], dist2[i]);
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
    return 0;
}