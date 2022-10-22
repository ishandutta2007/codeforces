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
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++) {
        ll n, m, k;
        cin >> n >> m >> k;
        ll res = k;
        if (k % 2 != n % 2) {
            res--;
        }
        if (k % 2 != m % 2) {
            res--;
        }
        if (max(n, m) > k) {
            cout << "-1\n";
        } else {
            cout << res << "\n";
        }
    }
}