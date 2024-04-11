#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e5 + 7;
const double EPS = 1e-8;
const int LOGN = 30;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    ll l, r, x, y, k;
    cin >> l >> r >> x >> y >> k;
    for (ll i = x; i <= y; i++) {
        ll b = i * k;
        if (b >= l && b <= r) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}