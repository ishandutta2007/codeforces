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
const ll LOG = 64;

ll A[LOG];

ll solve() {
    fill(A, A + LOG, 0);
    ll xo = 0, n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        xo ^= x;
        ll j = 0;
        while (x > 0) {
            A[j++] += x % 2;
            x /= 2;
        }
    }

    if (xo == 0) return cout << "DRAW" << endl, 0;
    for (int i = LOG - 1; i >= 0; i--) {
        if (A[i] & 1) {
            if (A[i] % 4 == 3 && (n - A[i]) % 2 == 0) return cout << "LOSE" << endl, 0;
            else return cout << "WIN" << endl, 0;
        }
    }
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}