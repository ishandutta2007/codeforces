#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll cntdig(ll n) {
    ll res = 0;
    while (n) {
        n /= 10;
        res++;
    }
    return res;
}

ll sumdig(ll n) {
    ll res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
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
    ll cnt = cntdig(n);
    ll x = 1;
    for (ll i = 0; i < cnt - 1; i++) {
        x *= 10;
    }
    x--;
    cout << sumdig(x) + sumdig(n - x);
}