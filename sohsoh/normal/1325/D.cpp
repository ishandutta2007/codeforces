/*
    Soheil Mohammadkhani
    IDK :)
*/


#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

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

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
    long long u, v; cin >> u >> v;
    if (u > v || u % 2 != v % 2) return cout << -1 << endl, 0;
    if (v == 0) return cout << 0 << endl, 0;
    if (u == v) return cout << 1 << endl << u << endl, 0;
    long long diff = (v - u) / 2;
    if ((u & diff) == 0) return cout << 2 << endl << u + diff << sep << diff << endl, 0;
    cout << 3 << endl << u << sep << diff << sep << diff << endl, 0;
    return 0;
}