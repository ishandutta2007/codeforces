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
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MAXN = 2e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 6; // 998244353; // 1e9 + 9;

ll solve() {
    ll l, r, m;
    cin >> l >> r >> m;
    for (int a = l; a <= r; a++) {
        ll x = floor(m / ld(a)) * a;
        if (x > 0 && m - x <= r - l) return cout << a << sep << r << sep << r - (m - x) << endl, 0;
        x = ceil(m / ld(a)) * a;
        if (x - m <= r - l) return cout << a << sep << r - (x - m) << sep << r << endl, 0;
    }
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}