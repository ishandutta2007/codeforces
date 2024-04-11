#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 2e6 + 7;
const double EPS = 1e-8;

ll power(ll a, ll k) {
    if (!k) {
        return 1;
    }
    ll b = power(a, k / 2);
    b = b * b % INF;
    if (k % 2) {
        return b * a % INF;
    } else {
        return b;
    }
}

vector <ll> fact, st;

void init() {
    fact.resize(MAXN, 0);
    st.resize(MAXN, 0);
    st[0] = 1;
    for (ll i = 1; i < MAXN; i++) {
        st[i] = st[i - 1] * 2LL % INF;
    }
    fact[0] = 1;
    for (ll i = 1; i < MAXN; i++) {
        fact[i] = fact[i - 1] * i % INF;
    }
}

ll rev(ll a) {
    return power(a, INF - 2);
}

ll C(ll n, ll k) {
    return fact[n] * rev(fact[k]) % INF * rev(fact[n - k]) % INF;
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
    init();
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++) {
        ll x, y;
        cin >> x >> y;
        ll res = st[y - 1];
        ll k = sqrt(x);
        for (ll j = 2; j <= k; j++) {
            ll cnt = 0;
            while (x % j == 0) {
                x /= j;
                cnt++;
            }
            if (cnt) {
                res *= C(y + cnt - 1, cnt);
                //cout << y + cnt << " " << cnt << " " << C(y + cnt, cnt) << "\n";
                res %= INF;
            }
        }
        if (x != 1) {
            res *= C(y, 1);
            res %= INF;
        }
        cout << res << "\n";
    }
}