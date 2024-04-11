#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

struct Seg {
    ll l, r, x;
};

bool operator<(Seg a, Seg b) {
    if (a.l == b.l) {
        if (a.r == b.r) {
            return a.x < b.x;
        }
        return a.r < b.r;
    }
    return a.l < b.l;
}

set <Seg> q;

void div(ll l) {
    auto it = q.upper_bound({l, INF, INF});
    it--;
    auto p = *it;
    if (p.l == l) {
        return;
    }
    q.erase(it);
    q.insert({p.l, l - 1, p.x});
    q.insert({l, p.r, p.x});
}

void add(ll l, ll r, ll x) {
    auto it = q.lower_bound({l, -1, -1});
    vector <Seg> erased;
    while (it != q.end() && (*it).r <= r) {
        erased.push_back(*it);
        it++;
    }
    for (auto p : erased) {
        q.erase(p);
        p.x += x;
        q.insert(p);
    }
}

void change(ll l, ll r, ll x) {
    auto it = q.lower_bound({l, -1, -1});
    vector <Seg> erased;
    while (it != q.end() && (*it).r <= r) {
        erased.push_back(*it);
        it++;
    }
    for (auto p : erased) {
        q.erase(p);
    }
    q.insert({l, r, x});
}

bool cmp(Seg a, Seg b) {
    return a.x < b.x;
}

ll get(ll l, ll r, ll x) {
    auto it = q.lower_bound({l, -1, -1});
    vector <Seg> erased;
    while (it != q.end() && (*it).r <= r) {
        erased.push_back(*it);
        it++;
    }
    sort(erased.begin(), erased.end(), cmp);
    ll cnt = 0;
    for (auto p : erased) {
        cnt += p.r - p.l + 1;
        if (cnt >= x) {
            return p.x;
        }
    }
    assert(false);
}

ll power(ll a, ll k, ll mod) {
    if (!k) {
        return 1;
    }
    ll b = power(a, k / 2, mod);
    b = b * b % mod;
    if (k % 2) {
        return b * a % mod;
    } else {
        return b;
    }
}

ll get_sum(ll l, ll r, ll x, ll y) {
    auto it = q.lower_bound({l, -1, -1});
    ll res = 0;
    while (it != q.end() && (*it).r <= r) {
        auto p = *it;
        res = (res + (p.r - p.l + 1LL) * power(p.x % y, x, y)) % y;
        it++;
    }
    return res;
}

ll n, m, seed, vmax;

ll rnd() {
    ll ret = seed;
    seed = (seed * 7LL + 13LL) % INF;
    return ret;
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
        //cout.tie(0);
    #endif // MY
    cin >> n >> m >> seed >> vmax;
    for (ll i = 0; i < n; i++) {
        ll x = rnd() % vmax + 1;
        q.insert({i, i, x});
    }
    for (ll i = 0; i < m; i++) {
        ll op = rnd() % 4 + 1;
        ll l = rnd() % n;
        ll r = rnd() % n;
        if (l > r) {
            swap(l, r);
        }
        //cout << op << " " << l << " " << r << "\n";
        div(l);
        if (r != n - 1) {
            div(r + 1);
        }
        ll x, y;
        if (op == 3) {
            x = rnd() % (r - l + 1) + 1;
        } else {
            x = rnd() % vmax + 1;
        }
        if (op == 4) {
            y = rnd() % vmax + 1;
        }
        if (op == 1) {
            add(l, r, x);
        } else if (op == 2) {
            change(l, r, x);
        } else if (op == 3) {
            cout << get(l, r, x) << "\n";
        } else {
            cout << get_sum(l, r, x, y) << "\n";
        }
    }
}