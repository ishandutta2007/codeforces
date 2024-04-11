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

ll B[MAXN] = {0}, A[MAXN];
ll n = 0;

ll solve() {
    fill(B, B + n + 10, 0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    ll m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        ll p, e;
        cin >> p >> e;
        B[e] = max(B[e], p);
    }

    for (int i = n; i >= 0; i--) B[i] = max(B[i], B[i + 1]);
    ll d = 0;
    ll mp = 0;

    ll k = 1;
    for (int i = 0; i < n; i++) {
        d++;
        mp = max(mp, A[i]);
        if (B[d] < mp) {
            mp = A[i];
            d = 1;
            k++;
        }

        if (B[d] < mp) return cout << -1 << endl, 0;
    }
    cout << k << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}