/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Candidate Master":)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define debug_p(x)                  cerr << #x << ": " <<  x.X <<  " " << x.Y << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10; // CHANGE IT :)
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll ps1[MAXN], ps2[MAXN];

ll solve() {
    string s;
    cin >> s;
    ll n = s.size();
    fill(ps1, ps1 + n + 10, 0);
    fill(ps2, ps2 + n + 10, 0);

    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (i > 0) {
            ps1[i] = ps1[i - 1];
            ps2[i] = ps2[i - 1];
        }
        if (c == '1') ps1[i]++;
        else ps2[i]++;
    }

    ll ans = INF;
    for (int i = 0; i < n; i++) {
        ll ans1 = ps1[i] + ps2[n - 1] - ps2[i];
        ll ans2 = ps2[i] + ps1[n - 1] - ps1[i];
        ans = min(ans, ans1);
        ans = min(ans, ans2);
    }

    cout << ans << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}