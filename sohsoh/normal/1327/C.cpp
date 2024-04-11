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
    int n, m, r;
    cin >> n >> m >> r;

    for (int i = 0; i < 2 * r; i++) {
        int t, c;
        cin >> t >> c;
    }

    if (m == 1 && n == 1) {
        cout << "0" << endl;
        return 0;
    }

    if (m == 1) {
        cout << 2 * n << endl;
        for (int i = 0; i < n; i++) {
            cout << "U";
        }
        for (int i = 0; i < n; i++) {
            cout << "D";
        }

        return 0;
    }

    if (n == 1) {
        cout << 2 * m << endl;
        for (int i = 0; i < m; i++) {
            cout << "R";
        }
        for (int i = 0; i < m; i++) {
            cout << "L";
        }

        return 0;
    }

    string s = "";
    int k = 0;
    for (int i = 0; i < n - 1; i++) {
        s += "U";
        k++;
    }
    for (int i = 0; i < m - 1; i++) {
        s += "L";
        k++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            k++;
            if (i % 2 == 0) {
                s += 'R';
            } else {
                s += 'L';
            }
        }

        if (i != n - 1) {
            s += 'D';
            k++;
        }
    }

    cout << k << endl;
    cout << s << endl;
    return 0;
}