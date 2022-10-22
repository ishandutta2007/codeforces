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
const ll MOD = 998244353; // 1e9 + 9;

int main() {
    int n, k;
    cin >> n >> k;
    pair<int, int>* a = new pair<int, int>[n];
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a[i] = make_pair(-1 * t, i);
    }
    sort(a, a + n);

    int* b = new int[k];
    long long sum = 0;
    for (int i = 0; i < k; i++) {
        sum += a[i].first;
        b[i] = a[i].second;
    }

    cout << -sum << " " ;
    sort(b, b + k);

    sum = 1;
    for (int i = 0; i < k; i++) {
        int diff = 0;
        if (i != 0)
            diff = b[i] - b[i - 1] - 1;
        if (diff == 0)
            continue;
        sum *= diff + 1;

        while (sum > MOD) {
            sum -= MOD;
        }
    }

    while (sum > MOD) {
        sum -= MOD;
    }

    cout << sum << endl;
}