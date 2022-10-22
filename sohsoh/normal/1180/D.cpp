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

ll n, m;

ll t_l(ll x) {
    ll y = n - x + 1;
    for (int i = 1; i <= m; i++) {
        cout << x << sep << i << endl;
        cout << y << sep << m - i + 1 << endl;
    }
}

int main() {
    fast_io;
    cin >> n >> m;
    for (int i = 1; i <= n / 2; i++) t_l(i);
    if (n % 2) {
        for (int i = 1; i <= m / 2; i++) {
            cout << n / 2 + 1 << sep << i << endl;
            cout << n / 2 + 1 << sep << m - i + 1 << endl;
        }

        if (m % 2) cout << n / 2 + 1 << sep << m / 2 + 1 << endl;
    }
    return 0;
}