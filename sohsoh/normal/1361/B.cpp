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

ll a[MAXN] = {0};
bool mark[MAXN];

ll Md(ll n) {
    return (n + MOD * 10) % MOD;
}

ll solve() {
    ll n, p;
    cin >> n >> p;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    reverse(a, a + n);
    ll needed = 0;

    for (int i = 0; i < n; i++) {
        if (needed <= 0) {
            mark[i] = true;
            needed++;
        } else {
            mark[i] = false;
            for (int j = a[i]; j < a[i - 1] && needed < MAXN && p != 1; j++) needed *= p;
            needed--;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (mark[i]) ans += poww(p, a[i], MOD);
        else ans -= poww(p, a[i], MOD);
        ans = Md(ans);
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