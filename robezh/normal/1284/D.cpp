#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)4e5 + 50;

int mods[7] = {(int)1e9 + 7, (int)1e9 + 9, (int)1e9 + 21, (int)1e9 + 33, 998244353, 1004535809, 469762049};
int p = 37;
int n;
int as[N], ae[N];
int bs[N], be[N];
int val[N], nval;

int get(int x) {
    return (int)(lower_bound(val, val + nval, x) - val);
}
struct eve {
    int x, in, id;
};

struct BIT {
    ll bit[N];
    int n;

    void clear() {
        n = nval;
        fill(bit, bit + nval, 0);
    }

    void add(int x, ll val) {
        for(int i = x; i < n; i |= i + 1) bit[i] += val;
    }

    ll get(int x) {
        ll res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
        return res;
    }

    ll get(int l, int r) {
        return get(r) - get(l - 1);

    }
} bit;

ll pw[N];

void add(ll &to, ll val, ll mod) {
    to += val;
    if(to >= mod) to -= mod;
}

vector<ll> solve(int *s, int *e, int p, int mod) {
    vector<eve> es;
    for(int i = 0; i < n; i++) {
        es.push_back({s[i], 1, i});
        es.push_back({e[i], 0, i});
    }
    pw[0] = 1;
    for(int i = 1; i <= n; i++) pw[i] = pw[i-1] * p % mod;
    bit.clear();
    sort(es.begin(), es.end(), [](const eve &e1, const eve &e2) {
        return e1.x == e2.x ? (e1.in > e2.in) : e1.x < e2.x;
    });
    vector<ll> res(n, 0);
    ll cur = 0;
    int r = 0;
    for(int i = 0; i < es.size(); i = r) {
        while(r < es.size() && es[r].x == es[i].x) {
            if(es[r].in) {
                add(cur, pw[es[r].id], mod);
            }
            else {
                add(cur, mod - pw[es[r].id], mod);
                bit.add(es[r].x, pw[es[r].id]);
            }
            r++;
        }
        for(int j = i; j < r; j++) {
            if(es[j].in) continue;
//            cout << "getting " << es[j].id << endl;
            res[es[j].id] = ((bit.get(s[es[j].id], nval - 1) + cur) % mod + mod) % mod;
        }
    }
    return res;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {

    std::shuffle(mods, mods + 7, rng);
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> as[i] >> ae[i] >> bs[i] >> be[i];
        val[nval++] = as[i];
        val[nval++] = ae[i];
        val[nval++] = bs[i];
        val[nval++] = be[i];
    }
    sort(val, val + nval);
    nval = (int)(unique(val, val + nval) - val);
    for(int i = 0; i < n; i++) {
        as[i] = get(as[i]);
        ae[i] = get(ae[i]);
        bs[i] = get(bs[i]);
        be[i] = get(be[i]);
//        cout << as[i] << " " << ae[i] << " " << bs[i] << " " << be[i] << endl;
    }
    for(int it = 0; it < 4; it++) {
//        cout << mods[it] << " ";
        vector<ll> v1 = solve(as, ae, p, mods[it]);
        vector<ll> v2 = solve(bs, be, p, mods[it]);
//        cout << "it1: " << endl;
//        for(ll x : v1) cout << x << " ";
//        cout << endl;
//        for(ll x : v2) cout << x << " ";
//        cout << endl;
        for(int i = 0; i < n; i++) {
            if(v1[i] != v2[i]) {
                return cout << "NO" << endl, 0;
            }
        }
    }
    cout << "YES" << endl;
}