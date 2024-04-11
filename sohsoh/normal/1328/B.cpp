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
    ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        ll a1 = -1, a2 = -1;
        ll ind = 0;
        ll all = (n - ind) * (n - ind - 1) / 2;
        long long x = n - 1;
        while (all != 0) {
            if (a1 == -1) {
                ll can = all - x;
//                cout << "CAN " << can << endl;
//                cout << "HHH" << can << endl;
                if (k > can) {
                    a1 = ind;
                    k -= can;
                    a2 = n - k;
//                    cout << a1 << " " << a2 << endl;
                    break;
                }
            }
            ind++;
                x--;
                all = (n - ind) * (n - ind - 1) / 2;
        }

        for (int i = 0; i < n; i++) {
            if (i == a1 || i == a2) {
                cout << 'b';
            } else {
                cout << 'a';
            }
        } cout << endl;
    }
    return 0;
}