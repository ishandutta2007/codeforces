#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)3e5 + 50;
vi G[N], H[N];
int tin[N], tout[N], tim = 0;
int n;

struct BIT {
    int n;
    int bit[N];

    void init(int _n) {
        n = _n;
        fill(bit, bit + n, 0);
    }

    void add(int x, int val) {
        for(int i = x; i < n; i |= i + 1) bit[i] += val;
    }

    int get(int x) {
        int res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
        return res;
    }

    int get_range(int l, int r) {
        return get(r) - get(l - 1);
    }

} bit[2];


void euler(int v) {
    tin[v] = tim++;
    for (int nxt : H[v]) euler(nxt);
    tout[v] = tim - 1;
}

int res, cs;

void add(int v, int d) {
    cs += d;
    bit[0].add(tin[v], d);
    bit[1].add(tin[v], d * (v + 1));
    bit[1].add(tout[v] + 1, -d * (v + 1));
}

void solve(int v) {
    vector<pii> upd;
    if(bit[0].get_range(tin[v], tout[v]) == 0) {
        int p = bit[1].get(tin[v]);
        if(p) upd.push_back({p - 1, -1});
        upd.push_back({v, 1});
    }
    for (auto p : upd) add(p.first, p.second);
    res = max(res, cs);
    for (int nxt : G[v]) {
        solve(nxt);
    }

    for (auto p : upd) add(p.first, -p.second);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        bit[0].init(n);
        bit[1].init(n);
        rep(i, 0, n) G[i].clear(), H[i].clear();
        rep(i, 1, n) {
            int p; cin >> p; p--;
            G[p].push_back(i);
        }
        rep(i, 1, n) {
            int p; cin >> p; p--;
            H[p].push_back(i);
        }
        res = cs = 0;

        tim = 0;
        euler(0);
        solve(0);
        cout << res << '\n';

    }

}