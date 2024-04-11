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
    ll n, d;
    cin >> n >> d;
    ll m;
    cin >> m;
    for (ll i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        if (y - x > d || y - x < -d) {
            cout << "NO\n";
            continue;
        }
        if (y + x < d || y + x > 2 * n - d) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
}