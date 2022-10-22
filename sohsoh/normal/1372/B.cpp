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

ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}

ll solve() {
    ll n;
    cin >> n;
    ll sq = sqrt(n);
    pll ans = {1, n - 1};
    ll ans_s = n - 1;
    for (int i = 1; i <= sq; i++) {
        if (n % i == 0) {
            ll new_lcm = lcm(i, n - i);
            if (new_lcm < ans_s) {
                ans = {i, n - i};
                ans_s = new_lcm;
            }

            ll x = n / i;
            if (x == n) continue;
            new_lcm = lcm(x, n - x);
            if (new_lcm < ans_s) {
                ans = {x, n - x};
                ans_s = new_lcm;
            }
        }
    }

    cout << ans.X << sep << ans.Y << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}