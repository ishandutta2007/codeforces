#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll calc(ll x) {
    if (x < 2) {
        return 0;
    }
    ll res = 0;
    ll now = 1;
    while (2 * now <= x) {
        res = 2 * res + now;
        now *= 2;
    }
    if (x == now) {
        return res;
    }
    return res + calc(x - now) + now;
}

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
    ll n;
    cin >> n;
    cout << calc(n);
}