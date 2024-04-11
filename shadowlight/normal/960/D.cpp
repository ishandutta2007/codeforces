#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

const ll LOGN = 61;

vector <ll> sh(LOGN, 0);
vector <ll> sz(LOGN);

ll add(ll a, ll b, ll p) {
    a += b;
    while (a >= p) {
        a -= p;
    }
    while (a < 0) {
        a += p;
    }
    return a;
}

ll mul(ll a, ll b, ll p) {
    if (!b) {
        return 0;
    }
    ll c = mul(a, b / 2, p);
    c = add(c, c, p);
    if (b % 2) {
        return add(c, a, p);
    } else {
        return c;
    }
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
    sz[0] = 1;
    for (ll i = 1; i < LOGN; i++) {
        sz[i] = 2 * sz[i - 1];
    }
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++) {
        ll tp;
        cin >> tp;
        if (tp == 3) {
            ll x;
            cin >> x;
            ll l = 1, r = 1;
            ll lvl = 0;
            while (x > r) {
                l = r + 1;
                r = 2 * r + 1;
                lvl++;
            }
            ll num = ((x - l) + sh[lvl]) % sz[lvl] + l;
            while (num) {
                ll val = (num - l - sh[lvl] + sz[lvl]) % sz[lvl] + l;
                cout << val << " ";
                lvl--;
                num /= 2;
                l = (1LL << lvl);
            }
            cout << "\n";
            continue;
        }
        ll x, k;
        cin >> x >> k;
        ll l = 1, r = 1;
        ll lvl = 0;
        while (x > r) {
            l = r + 1;
            r = 2 * r + 1;
            lvl++;
        }
        if (tp == 1) {
            sh[lvl] = (sh[lvl] + k) % sz[lvl];
            sh[lvl] = add(sh[lvl], sz[lvl], sz[lvl]);
        } else {
            ll now = 1;
            k %= sz[lvl];
            for (; lvl < LOGN; lvl++) {
                sh[lvl] = add(sh[lvl], k, sz[lvl]);
                sh[lvl] = add(sh[lvl], sz[lvl], sz[lvl]);
                k *= 2;
            }
        }
    }
}