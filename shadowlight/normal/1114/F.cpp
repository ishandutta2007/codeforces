#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 307;
const ll N = 4e5 + 7;
const ll SQ = 700;
const double EPS = 1e-6;
const ll Q = 20;
const ll PSZ = 63;

ll n, q;

ll power(ll a, ll k) {
    if (!k || a == 1) {
        return 1;
    }
    ll b = power(a, k / 2);
    b = b * (ll) b % INF;
    if (k % 2) {
        return a * (ll) b % INF;
    } else {
        return b;
    }
}

ll rev(ll a) {
    return power(a, INF - 2);
}

ll st[MAXN][Q];
ll revs[MAXN];

vector <pair <ll, ll> > f[MAXN];
vector <ll> ps, num;

void mult(ll &x, ll y) {
    x = x * (ll) y % INF;
}

void init() {
    num.resize(MAXN, -1);
    for (ll i = 0; i < MAXN; i++) {
        ll now = 1;
        //cout << i << " " << j << "\n";
        for (ll j = 0; j < Q; j++) {
            st[i][j] = now;
            now = now * (ll) i % INF;
        }
    }
    for (ll i = 2; i < MAXN; i++) {
        ll t = i;
        for (ll j = 2; j <= i; j++) {
            ll cnt = 0;
            while (t % j == 0) {
                cnt++;
                t /= j;
            }
            if (cnt) {
                if (num[j] == -1) {
                    num[j] = ps.size();
                    ps.push_back(j);
                }
                f[i].push_back({j, cnt});
            }
        }
    }
    for (ll i = 1; i < MAXN; i++) {
        revs[i] = (i - 1) * (ll) rev(i) % INF;
    }
}

bool emp[PSZ];

struct Tree {
    ll t[4 * N], add[4 * N];
    ll mask[4 * N], pmask[4 * N];
    void init() {
        for (ll i = 0; i < 4 * N; i++) {
            t[i] = 1;
            add[i] = 1;
            mask[i] = 0;
            pmask[i] = 0;
        }
    }
    void relax(ll v) {
        t[v] = t[2 * v] * (ll) t[2 * v + 1] % INF;
        mask[v] = mask[2 * v] | mask[2 * v + 1];
    }
    void add_val(ll v, ll lt, ll rt, ll val, ll upd) {
        mult(t[v], power(val, rt - lt));
        mult(add[v], val);
        mask[v] |= upd;
        pmask[v] |= upd;
    }
    void push(ll v, ll lt, ll rt) {
        ll mt = (lt + rt) / 2;
        add_val(2 * v, lt, mt, add[v], pmask[v]);
        add_val(2 * v + 1, mt, rt, add[v], pmask[v]);
        add[v] = 1;
    }
    void add_seg(ll l, ll r, ll val, ll nmask, ll lt = 0, ll rt = n, ll v = 1) {
        if (l >= rt || lt >= r) {
            return;
        }
        if (l <= lt && rt <= r) {
            add_val(v, lt, rt, val, nmask);
            return;
        }
        push(v, lt, rt);
        ll mt = (lt + rt) / 2;
        add_seg(l, r, val, nmask, lt, mt, 2 * v);
        add_seg(l, r, val, nmask, mt, rt, 2 * v + 1);
        relax(v);
    }
    ll get(ll l, ll r, ll &nmask, ll lt = 0, ll rt = n, ll v = 1) {
        if (l >= rt || lt >= r) {
            return 1;
        }
        if (l <= lt && rt <= r) {
            nmask |= mask[v];
            return t[v];
        }
        push(v, lt, rt);
        ll mt = (lt + rt) / 2;
        auto a = get(l, r, nmask, lt, mt, 2 * v);
        auto b = get(l, r, nmask, mt, rt, 2 * v + 1);
        relax(v);
        return a * (ll) b % INF;
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
    cin >> n >> q;
    Tree t;
    t.init();
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        ll mask = 0;
        ll now = 1;
        for (auto t : f[x]) {
            mask += (1LL << num[t.first]);
            //cout << num[t.first] << " ";
        }
        //cout << "\n";
        t.add_seg(i, i + 1, x, mask);
    }
    for (ll i = 0; i < q; i++) {
        string tp;
        cin >> tp;
        ll l, r;
        cin >> l >> r;
        l--, r--;
        if (tp == "TOTIENT") {
            ll mask = 0;
            ll res = t.get(l, r + 1, mask);
            for (ll i = 0; i < PSZ; i++) {
                if (mask & (1LL << i)) {
                    mult(res, revs[ps[i]]);
                    //cout << ps[i] << " ";
                }
            }
            //cout << "\n";
            cout << res << "\n";
        } else {
            ll val;
            cin >> val;
            ll mask = 0;
            for (auto t : f[val]) {
                mask += (1LL << num[t.first]);
            }
            t.add_seg(l, r + 1, val, mask);
        }
    }
}