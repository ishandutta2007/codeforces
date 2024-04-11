/*
    Soheil Mohammadkhani
    IDK :)
*/


#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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

int n;
int ni(int ind) {
    if (ind + 1 < n) return ind + 1;
    return 0;
}

int pi(int ind) {
    if (ind > 0) return ind - 1;
    return n - 1;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int* a = new int[n];
        int* col = new int[n];
        pair<bool, bool>* pn = new pair<bool, bool>[n];

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            pn[i] = make_pair(a[i] == a[pi(i)], a[i] == a[ni(i)]);
        }

        int cr = 0;
        col[0] = 0;

        for (int i = 1; i < n; i++) {
            if (pn[i].first) col[i] = col[i - 1];
            else {
                cr ++;
                cr = cr % 2;
                col[i] = cr;
            }
        }

        bool ok = ((a[0] != a[n - 1]) && (col[0] == col[n - 1]));
        if (ok) {
            for (int i = 1; i < n; i++) {
                if (col[i] == col[i - 1]) {
                    for (int j = i; j < n; j++) {
                        col[j] = !col[j];
                    }

                    ok = false;
                    break;
                }
            }

            if (ok) {
                col[0] = 2;
            }
        }

        cout << *max_element(col, col + n) + 1 << endl;
        for (int i = 0; i < n; i++) {
            cout << col[i] + 1 << ' ';
        }
        cout << endl;
    }

    return 0;
}