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
    ll n, a, b;
    cin >> n >> a >> b;
    for (ll x = 0; x <= n; x++) {
        if (x * a > n) break;
        if ((n - x * a) % b == 0) {
            cout << "YES\n";
            cout << x << " " << (n - x * a) / b;
            return 0;
        }
    }
    cout << "NO\n";
}