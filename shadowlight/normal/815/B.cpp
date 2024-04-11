#include <bits/stdc++.h>

#define ll long long
#define TASKNAME ""

const ll INF = 1e9 + 7;
const double EPS = 1e-8;
const ll MAXN = 1e6 + 7;

using namespace std;

ll power(ll a, ll k) {
    if (!k) {
        return 1;
    }
    ll b = power(a, k / 2);
    b = (b * b) % INF;
    if (k % 2) {
        return b * a % INF;
    } else {
        return b;
    }
}

vector <ll> f;

ll rev(ll a) {
    return power(a, INF - 2);
}

ll C(ll k, ll n) {
    //assert(k <= n);
    if (k > n) {
        return 0;
    }
    ll a = f[n];
    ll b = rev(f[k]);
    ll c = rev(f[n - k]);
    return a * b % INF * c % INF;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    ll n;
    cin >> n;
    vector <ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    f.resize(MAXN, 0);
    f[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        f[i] = f[i - 1] * i % INF;
    }
    vector <ll> coef(n);
    if (n % 4 == 0) {
        for (int i = 0; i < n; i++) {
            coef[i] = C(i / 2, n / 2 - 1) * (i % 2 ? -1 : 1);
        }
    } else if (n % 4 == 1) {
        for (int i = 0; i < n; i++) {
            coef[i] = C(i / 2, (n - 1) / 2) * (i % 2 ? 0 : 1);
        }
    } else if (n % 4 == 2) {
        for (int i = 0; i < n; i++) {
            coef[i] = C(i / 2, (n - 2) / 2);
        }
    } else {
        coef[0] = C(0, (n - 3) / 2);
        for (int i = 1; i < n; i++) {
            coef[i] = i % 2 ? 2 * C(i / 2, (n - 3) / 2) : C(i / 2, (n - 3) / 2) - C(i / 2 - 1, (n - 3) / 2);
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += coef[i] * a[i] % INF;
        ans %= INF;
    }
    cout << (ans + INF) % INF;
}