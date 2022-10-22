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

void solve() {
    int n;
    cin >> n;

    int g = -1;
    bool* avai = new bool[n];
    for (int i = 0; i < n; i++) {
        avai[i] = true;
    }

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        bool mar = false;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            x--;
            if (avai[x] && !mar) { avai[x] = false; mar = true;}
        }

        if (!mar && g == -1) g = i;
    }

    if (g != -1) {
//        cout << g << endl;
        for (int i = 0; i < n; i++) {
            if (avai[i]) {
                cout << "IMPROVE" << endl;
                cout << g + 1 << " " << i + 1 << endl;
                return;
            }
        }
    }

    cout << "OPTIMAL" << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}