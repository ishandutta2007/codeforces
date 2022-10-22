#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll getp(ll x) {
    ll y = x;
    ll res = 0;
    ll st = 1;
    while (x) {
        res = res * 10 + x % 10;
        x /= 10;
        st *= 10;
    }
    return y * st + res;
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
    ll k, p;
    cin >> k >> p;
    ll sum = 0;
    for (ll i = 1; i <= k; i++) {
        sum += getp(i);
        sum %= p;
    }
    cout << sum;
}