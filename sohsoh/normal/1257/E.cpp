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
const ll INF = 8e17;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN], k1, k2, k3, n, dp[MAXN];
pll dp_t[MAXN];
vector<ll> v;

// Finally finished this fucking Q

int main() {
    fast_io;
    cin >> k1 >> k2 >> k3;
    n = k1 + k2 + k3;
    for (int i = 0; i < k1; i++) {
        ll x;
        cin >> x;
        A[x] = 1;
    }

    for (int i = 0; i < k2; i++) {
        ll x;
        cin >> x;
        A[x] = 2;
        v.push_back(x);
    }

    for (int i = 0; i < k3; i++) {
        ll x;
        cin >> x;
        A[x] = 3;
        v.push_back(x);
    }

    sort(all(v));
    reverse(all(v));

    dp_t[0] = {0, 0};
    ll i = 0;
    for (ll e : v) {
        i++;
        if (A[e] == 2) {
            dp_t[i].Y = dp_t[i - 1].Y + 1;
            dp_t[i].X = min(dp_t[i - 1].X, dp_t[i - 1].Y);
        } else {
            dp_t[i].Y = dp_t[i - 1].Y;
            dp_t[i].X = min(dp_t[i - 1].X, dp_t[i - 1].Y) + 1;
        }
    }

    for (int i = 0; i <= v.size(); i++) {
        dp[i] = min(dp_t[i].X, dp_t[i].Y);
    }

    ll e = v.size(), ans = k1 + dp[v.size()];
    ll g = 0;
    for (i = 1; i <= n; i++) {
        if (A[i] != 1) {
            g++;
            e--;
        } else k1--;

        ans = min(ans, k1 + g + dp[e]);
    }

    cout << ans << endl;

    return 0;
}