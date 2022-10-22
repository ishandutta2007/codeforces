/*
    Soheil Mohammadkhani
    IDK :)
*/


#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

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
#define SZ(x)                       ll(x.size());
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define bug(x)                    cerr << #x << ": " <<  x <<  " ";

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int solve() {
    unsigned long long n, x;
    cin >> n >> x;
    unsigned long long* a = new unsigned long long[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return cout << 1 << endl, 0;
        }
    }

    unsigned long long m = *max_element(a, a + n);
    if (m > x) return cout << 2 << endl, 0;

    if (x % m == 0) return cout << x / m << endl, 0;
    cout << x / m + 1 << endl;
}

int main() {
//    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); //cout << "__________________________________________" << endl;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}