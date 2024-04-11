/*
    Soheil Mohammadkhani
    i'm sad :(
    aghayi ke dari in code ro mikhooi, in kod copyie :|
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
#define bug(x)                      cerr << #x << ": " <<  x <<  " ";
#define alog(a, n)                  for (int i = 2; i <= n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll solve() {
    ll n, d;
    cin >> n >> d;
    d = (n * (n - 1) / 2) - d;
    if (d < 0) return cout << "NO" << endl, 0;

    ll* p = new ll[n + 1];
    for (int i = 0; i < n + 1; i++) p[i] = i - 1;
    queue<pll> rem, new_row;
    rem.push({1, 1});

    ll dep = 2;

    for (int i = n; i > 1; i--) {
        ll loss = i - dep;
        if (d - loss < 0) {
            p[i] -= d;
            d = 0;
            break;
        }

        rem.front().Y--;
        d -= loss;
        p[i] = rem.front().X;
        new_row.push({i, 2});
        if (rem.front().Y < 1) rem.pop();
        if (rem.empty()) {
            rem.push({dep, 1});
            dep++;
            while (!new_row.empty()) {
                rem.push(new_row.front());
                new_row.pop();
            }
        }

        if (d == 0) break;
    }

    if (d > 0) return cout << "NO" << endl, 0;
    cout << "YES" << endl;
    alog(p, n);
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}