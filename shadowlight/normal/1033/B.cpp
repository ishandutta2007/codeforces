#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const ll MAXN = 2e6 + 7;
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
    ll t;
    cin >> t;
    for (ll id = 0; id < t; id++) {
        ll b, a;
        cin >> a >> b;
        if (a > b + 1) {
            cout << "NO\n";
            continue;
        }
        ll x = 2 * b + 1;
        bool isp = true;
        for (ll j = 2; j < min(MAXN, x); j++) {
            if (x % j == 0) {
                isp = false;
                break;
            }
        }
        cout << (isp ? "YES\n" : "NO\n");
    }
}