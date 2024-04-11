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
    ll a, b;
    cin >> a >> b;
    if (b - a > 10) {
        cout << 0;
        return 0;
    }
    ll res = 1;
    for (ll i = a + 1; i <= b; i++) {
        res *= i % 10;
        res %= 10;
    }
    cout << res;
}