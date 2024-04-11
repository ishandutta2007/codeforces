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

const ll MAXN = 2000 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll solve() {
    ll n;
    cin >> n;
    ll r = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (x % 2 == 0) {
            cout << x / 2 << endl;
        } else {
            if (r > 0) {
                cout << ll(floor(x / 2.0)) << endl;
                r--;
            } else {
                cout << ll(ceil(x / 2.0)) << endl;
                r++;
            }
        }
    }
}

int main() {
    fast_io;
    solve();
    return 0;
}