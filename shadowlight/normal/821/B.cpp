#include <bits/stdc++.h>

#define ll long long
#define TASKNAME ""

const int INF = 1e9 + 7;
const double EPS = 1e-8;
const int MAXN = 1e6 + 7;

using namespace std;

ll cnt(ll x, ll y) {
    return x * (y + 1) * (x + 1) / 2 + (x + 1) * y * (y + 1) / 2;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    ll m, b;
    cin >> m >> b;
    ll maxk = 0;
    for (ll i = 0; i <= m * b; i++) {
        ll y = b - i / m;
        if (i % m) y--;
        maxk = max(maxk, cnt(i, y));
    }
    cout << maxk;
}