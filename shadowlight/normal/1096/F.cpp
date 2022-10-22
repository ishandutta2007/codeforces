#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const ll INF = 998244353;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-6;

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

vector <ll> f;

void init() {
    f.resize(MAXN, 0);
    f[0] = 1;
    for (ll i = 1; i < MAXN; i++) {
        f[i] = f[i - 1] * i % INF;
    }
}

ll rev(ll a) {
    return power(a, INF - 2);
}

struct Tree {
    ll n;
    vector <ll> t;
    Tree(ll n) : n(n), t(2 * n, 0) {}
    ll get(ll l, ll r) {
        ll res = 0;
        for (l += n, r += n; l <= r; l /= 2, r /= 2) {
            if (l % 2 == 1) {
                res += t[l++];
            }
            if (r % 2 == 0) {
                res += t[r--];
            }
        }
        return res;
    }
    void add(ll v, ll x) {
        v += n;
        while (v) {
            t[v] += x;
            v /= 2;
        }
    }
};

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
    ll n;
    cin >> n;
    vector <ll> p(n);
    ll cnt = 0;
    Tree t(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        cin >> p[i];
        if (p[i] == -1) {
            cnt++;
        } else {
            p[i]--;
            sum += t.get(p[i], n - 1);
            sum %= INF;
            t.add(p[i], 1);
        }
    }
    ll bot = f[cnt];
    ll top = 0;
    ll a1 = 0, a2 = 0, a3 = 0;
    vector <ll> cd(n + 1, 0);
    cd[0] = 0;
    for (ll i = 1; i <= n; i++) {
        cd[i] = ((i * (i - 1) / 2) % INF * f[i - 1] + i * cd[i - 1]) % INF;
    }
    a1 = cd[cnt];
    a2 = sum * bot % INF;
    ll space = cnt;
    ll last = 0;
    for (ll i = 0; i < n; i++) {
        if (p[i] == -1) {
            space--;
            last++;
            continue;
        }
        ll now = p[i] + 1 - t.get(0, p[i]);
        a3 += now * space;
        ll now2 = (n - p[i]) - t.get(p[i], n - 1);
        a3 += now2 * last;
        a3 %= INF;
    }
    if (cnt) {
        a3 = a3 * f[cnt - 1] % INF;
    }
    top = (a1 + a2 + a3) % INF;
    //cout << a1 << " " << a2 << " " << a3 << " " << bot << "\n";
    cout << top * rev(bot) % INF;
}