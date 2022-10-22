#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll v1, v2, v3, vm;
    cin >> v1 >> v2 >> v3 >> vm;
    for (ll i = v1; i <= 2 * v1; i++) {
        for (ll j = v2; j <= 2 * v2; j++) {
            for (ll k = v3; k <= 2 * v3; k++) {
                if (!(i > j && j > k)) {
                    continue;
                }
                if (2 * vm >= i) continue;
                if (2 * vm >= j) continue;
                if (vm > k || 2 * vm < k) continue;
                cout << i << "\n" << j << "\n" << k;
                return 0;
            }
        }
    }
    cout << "-1";
}