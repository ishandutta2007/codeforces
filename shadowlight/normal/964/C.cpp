#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 9;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll power(ll a, ll k) {
    if (!k) {
        return 1;
    }
    ll b = power(a, k / 2);
    b = b * b % INF;
    if (k % 2) {
        return a * b % INF;
    } else {
        return b;
    }
}

ll rev(ll a) {
    return power(a, INF - 2);
}

ll f(ll a, ll n) {
    if (a == 1) {
        return n + 1;
    }
    return (power(a, n + 1) - 1) * rev(a - 1) % INF;
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
    ll n, a, b, k;
    cin >> n >> a >> b >> k;
    ll st = 0;
    for (int i = 0; i < k; i++) {
        char c;
        cin >> c;
        st = (st + (c == '+' ? 1 : -1) * power(a, n - i) % INF * power(b, i) % INF + INF) % INF;
    }
    ll res = st * f(power(b, k) * rev(power(a, k)) % INF, (n + 1) / k - 1) % INF;
    cout << res;
}