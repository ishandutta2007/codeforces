#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 2e18 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

const ll LOGN = 60;

vector <ll> st[LOGN];

ll power(ll a, ll k) {
    if (!k) {
        return 1;
    }
    ll b = power(a, k / 2);
    if (b && b > INF / b) {
        return INF;
    }
    b = b * b;
    if (k % 2) {
        if (a && b > INF / a) {
            return INF;
        }
        return b * a;
    } else {
        return b;
    }
}

void init() {
    for (ll i = 3; i < LOGN; i++) {
        for (ll j = 0; j < MAXN; j++)  {
            ll x = power(j, i);
            if (x == INF) break;
            //cout << x << " " << j << " " << i << "\n";
            st[i].push_back(x);
        }
    }
}

ll get_sqrt(ll n, ll k) {
    if (k == 2) {
        return sqrtl(n);
    }
    ll v = upper_bound(st[k].begin(), st[k].end(), n) - st[k].begin();
    //cout << n << " " << k << " " << v - 1 << "\n";
    return v - 1;
}

vector <ll> calc(MAXN, -1);

ll get(ll x) {
    if (x < MAXN && calc[x] != -1) {
        return calc[x];
    }
    if (x < 2) {
        return 0;
    }
    ll res = x - 1;
    for (ll i = 2; i < LOGN; i++) {
        res -= get(get_sqrt(x, i));
    }
    if (x < MAXN) {
        calc[x] = res;
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
    init();
    //cout << "kek\n";
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        cout << get(x) << "\n";
    }
}