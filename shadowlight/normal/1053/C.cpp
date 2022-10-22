#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll n, q;

void norm(ll &x) {
    x %= INF;
    if (x < 0) {
        x += INF;
    }
}

void add(ll &x, ll y) {
    x += y;
    norm(x);
}

struct Tree {
    vector <ll> t;
    bool fl;
    void relax(ll v) {
        t[v] = t[2 * v] + t[2 * v + 1];
        if (fl) {
            norm(t[v]);
        }
    }
    void build(vector <ll> &a, ll l = 0, ll r = n, ll v = 1) {
        if (r - l == 1) {
            t[v] = a[l];
            if (fl) {
                norm(t[v]);
            }
            return;
        }
        ll m = (l + r) / 2;
        build(a, l, m, 2 * v);
        build(a, m, r, 2 * v + 1);
        relax(v);
    }
    Tree(vector <ll> &a, bool fl) : fl(fl) {
        t.resize(4 * n, 0);
        build(a);
    }
    ll get(ll l, ll r, ll tl = 0, ll tr = n, ll v = 1) {
        if (l >= tr || tl >= r) {
            return 0;
        }
        if (l <= tl && tr <= r) {
            return t[v];
        }
        ll tm = (tl + tr) / 2;
        ll sum = get(l, r, tl, tm, 2 * v) + get(l, r, tm, tr, 2 * v + 1);
        if (fl) {
            norm(sum);
        }
        return sum;
    }
    pair <ll, ll> force(ll l, ll sum, ll tl = 0, ll tr = n, ll v = 1) {
        if (tr <= l) {
            return {-1, 0};
        }
        if (t[v] < sum && tl >= l) {
            return {-1, t[v]};
        }
        if (tr - tl == 1) {
            return {tl, t[v]};
        }
        ll tm = (tl + tr) / 2;
        auto p = force(l, sum, tl, tm, 2 * v);
        if (p.first != -1) {
            return p;
        }
        auto p1 = force(l, sum - p.second, tm, tr, 2 * v + 1);
        return {p1.first, p1.second + p.second};
    }
    void change(ll p, ll x, ll tl = 0, ll tr = n, ll v = 1) {
        if (tl > p || tr <= p) {
            return;
        }
        if (tr - tl == 1) {
            t[v] = x;
            if (fl) {
                norm(t[v]);
            }
            return;
        }
        ll tm = (tl + tr) / 2;
        change(p, x, tl, tm, 2 * v);
        change(p, x, tm, tr, 2 * v + 1);
        relax(v);
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
    cin >> n >> q;
    vector <ll> a(n), w(n), b(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> w[i];
        b[i] = (a[i] - i) * w[i] % INF;
    }
    Tree tw(w, false);
    Tree tb(b, true);
    for (ll i = 0; i < q; i++) {
        ll x, y;
        cin >> x >> y;
        if (x < 0) {
            x = abs(x) - 1;
            tw.change(x, y);
            tb.change(x, (a[x] - x) * y);
        } else {
            ll l = x - 1, r = y - 1;
            ll sum = tw.get(l, r + 1);
            auto p = tw.force(l, (sum + 1) / 2);
            assert(p.first != -1);
            assert(tw.get(l, p.first) < (sum + 1) / 2);
            assert(tw.get(l, p.first + 1) >= (sum + 1) / 2);
            ll pos = p.first;
            ll res = 0;
            add(res, tw.get(pos + 1, r + 1) % INF * (pos - a[pos]));
            add(res, tb.get(pos + 1, r + 1));
            add(res, tw.get(l, pos) % INF * (a[pos] - pos));
            add(res, -tb.get(l, pos));
            cout << res << "\n";
        }
    }
}