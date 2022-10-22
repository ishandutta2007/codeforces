#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e18 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <ll> a;
ll n;

bool check_good(ll pos) {
    if (pos <= 0 || pos >= n - 1) return false;
    return a[pos - 1] <= 0 && a[pos] >= 0;
}

bool check_bad(ll pos) {
    if (pos <= 0 || pos >= n - 1) return false;
    return a[pos - 1] >= 0 && a[pos] <= 0;
}

struct Tree {
    vector <ll> mint, maxt;
    ll n;
    Tree(ll n) : n(n), mint(2 * n, INF), maxt(2 * n, -INF) {}
    void build(vector <ll> &a) {
        for (ll i = 0; i < n; i++) {
            mint[i + n] = a[i];
            maxt[i + n] = a[i];
        }
        for (ll i = n - 1; i >= 1; i--) {
            mint[i] = min(mint[2 * i], mint[2 * i + 1]);
            maxt[i] = max(maxt[2 * i], maxt[2 * i + 1]);
        }
    }
    void change(ll p, ll x) {
        p += n;
        mint[p] = x;
        maxt[p] = x;
        p /= 2;
        while (p) {
            mint[p] = min(mint[2 * p], mint[2 * p + 1]);
            maxt[p] = max(maxt[2 * p], maxt[2 * p + 1]);
            p /= 2;
        }
    }
    ll get_min(ll l, ll r) {
        ll res = INF;
        l = max(l, 0LL);
        r = min(r, n - 1);
        for (l += n, r += n; l <= r; l /= 2, r /= 2) {
            if (l % 2 == 1) {
                res = min(res, mint[l++]);
            }
            if (r % 2 == 0) {
                res = min(res, mint[r--]);
            }
        }
        return res;
    }
    ll get_max(ll l, ll r) {
        ll res = -INF;
        for (l += n, r += n; l <= r; l /= 2, r /= 2) {
            if (l % 2 == 1) {
                res = max(res, maxt[l++]);
            }
            if (r % 2 == 0) {
                res = max(res, maxt[r--]);
            }
        }
        return res;
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
    cin >> n;
    set <ll> good, bad;
    a.resize(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll sum = 0;
    for (ll i = 0; i < n - 1; i++) {
        a[i] -= a[i + 1];
        sum += abs(a[i]);
    }
    Tree t(n);
    t.build(a);
    for (ll i = 1; i < n - 1; i++) {
        if (check_good(i)) {
            good.insert(i);
        } else if (check_bad(i)) {
            bad.insert(i);
        }
    }
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++) {
        ll tp;
        cin >> tp;
        if (tp == 1) {
            ll l, r, x;
            cin >> l >> r >> x;
            l--, r--;
            auto it = good.lower_bound(l);
            if (it != good.end() && *it <= r) {
                cout << sum + 2 * x << "\n";
                continue;
            }
            ll res = -1;
            ll pos = r + 1;
            auto it1 = bad.lower_bound(l);
            if (it1 != bad.end() && *it1 <= r) {
                pos = *it1;
                //cout << pos << "\n";
                res = max(res, sum - abs(a[pos - 1]) - abs(a[pos]) + abs(a[pos - 1] - x) + abs(a[pos] + x));
                //cout << sum - abs(a[pos - 1]) - abs(a[pos]) + abs(a[pos - 1] - x) + abs(a[pos] + x) << "\n";
            } else if (a[l] <= 0) {
                pos = l - 1;
            }
            if (!l) {
                res = max(res, sum - abs(a[0]) + abs(a[0] + x));
            }
            if (r == n - 1) {
                res = max(res, sum - abs(a[n - 2]) + abs(a[n - 2] - x));
            }
            //cout << pos << "\n";
            if (l - 1 <= pos - 2) {
                ll mink = t.get_min(l - 1, pos - 2);
                //cout << mink << "\n";
                assert(mink >= 0);
                res = max(res, sum + x - abs(mink) + abs(mink - x));
            }
            if (pos + 1 <= r) {
                ll maxk = t.get_max(pos + 1, r);
                //cout << maxk << "\n";
                assert(maxk <= 0);
                res = max(res, sum + x - abs(maxk) + abs(maxk + x));
            }
            cout << res << "\n";
        } else {
            ll l, r, x;
            cin >> l >> r >> x;
            l--, r--;
            vector <ll> mas = {l - 1, l, r, r + 1};
            if (l) {
                sum -= abs(a[l - 1]);
                a[l - 1] -= x;
                sum += abs(a[l - 1]);
                t.change(l - 1, a[l - 1]);
            }
            if (r < n - 1) {
                sum -= abs(a[r]);
                a[r] += x;
                sum += abs(a[r]);
                t.change(r, a[r]);
            } else {
                a[r] += x;
                t.change(r, a[r]);
            }
            for (ll x : mas) {
                good.erase(x);
                bad.erase(x);
                if (check_good(x)) {
                    good.insert(x);
                }
                if (check_bad(x)) {
                    bad.insert(x);
                }
            }
        }
    }
}