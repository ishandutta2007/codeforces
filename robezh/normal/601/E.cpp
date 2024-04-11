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
#define lson(x) 2 * x + 1
#define rson(x) 2 * x + 2
const int INF = (int)1e9 + 50;

const int N = 15005, W = 1005, Q = 30050;
const int P = (int)1e7 + 19, MOD = (int)1e9 + 7;
int dp[N][W];
int sz = 0;

vector<pii> upd[Q * 4];

int n, k, q;
map<int, int> las;
vector<pii> p;
int isq[Q];
ll res[Q];

void update(int v, int w) {
    for (int j = k; j >= 0; j--) dp[sz][j] = dp[sz - 1][j];
    for (int j = k; j >= w; j--) dp[sz][j] = max(dp[sz][j], dp[sz - 1][j - w] + v);
    sz++;
}

void add_upd(int a, int b, int x, int l, int r, pii &p) {
    if(a > r || b < l) return ;
    if(a <= l && r <= b) {
        upd[x].push_back(p);
        return ;
    }
    int mid = (l + r) / 2;
    add_upd(a, b, lson(x), l, mid, p);
    add_upd(a, b, rson(x), mid + 1, r, p);
}

void solve(int x, int l, int r) {
    int lsz = sz;
    for (auto &u : upd[x]) {
        update(u.first, u.second);
    }

    if(l == r) {
        if(isq[l]) {
            for (int i = k; i >= 1; i--) {
                res[l] = (res[l] * P + dp[sz - 1][i]) % MOD;
            }
        }
    } else {
        int mid = (l + r) / 2;
        solve(lson(x), l, mid);
        solve(rson(x), mid + 1, r);
    }

    sz = lsz;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    p.resize(n);
    rep(i, 0, n) {
        cin >> p[i].first >> p[i].second;
        las[i] = 0;
    }
    cin >> q;
    rep(i, 0, q) {
        int tp; cin >> tp;
        if(tp == 1) {
            int v, w; cin >> v >> w;
            las[sz(p)] = i;
            p.push_back({v, w});
        } else if(tp == 2) {
            int x; cin >> x; x--;
            add_upd(las[x], i, 0, 0, q - 1, p[x]);
            las.erase(x);
        } else {
            isq[i] = 1;
        }
    }
    for (auto &u : las) {
        add_upd(u.second, q - 1, 0, 0, q - 1, p[u.first]);
    }

    sz = 1;

    solve(0, 0, q - 1);
    rep(i, 0, q) {
        if(isq[i]) cout << res[i] << '\n';
    }


}