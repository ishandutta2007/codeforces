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

const ll MAXN = 1e2 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll col[MAXN], row[MAXN];

ll solve() {
    ll n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) row[i] = true;
    for (int j = 0; j < m; j++) col[j] = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ll c;
            cin >> c;
            if (c == 1) {
                row[i] = false;
                col[j] = false;
            }
        }
    }

    ll poss = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] && col[j]) {
                poss++;
                row[i] = false;
                col[j] = false;
            }
        }
    }

    if (poss % 2 == 0) return cout << "Vivek" << endl, 0;
    cout << "Ashish" << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}