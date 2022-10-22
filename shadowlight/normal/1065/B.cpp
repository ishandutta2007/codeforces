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
    ll n, m;
    cin >> n >> m;
    ll now = 0;
    for (now = 0; now <= n; now++) {
        if (now * (now - 1) / 2 >= m) break;
    }
    if (m > n / 2) {
        cout << 0 << " ";
    } else {
        cout << n - 2 * m << " ";
    }
    cout << n - now << "\n";
}