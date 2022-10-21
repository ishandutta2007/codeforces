#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ll INF = (ll)5e18;
const int N = (int)3e5 + 50;

int n, q;
ll bit[N];

void add(int x, ll val) {
    for(int i = x; i < n; i |= i + 1) bit[i] = min(bit[i], val);
}

ll get(int x) {
    ll res = INF;
    for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res = min(res, bit[i]);
    return res;
}


vector<pll> upd[N];
int x[N], w[N];
vector<pii> qrs[N];
ll res[N];


void add_pt(int i, int j) {
    if(i > j) swap(i, j);
    upd[i].push_back({1LL * abs(x[i] - x[j]) * (w[i] + w[j]), j});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fill(bit, bit + N, INF);


    cin >> n >> q;
    rep(i, 0, n) cin >> x[i] >> w[i];
    vector<pii> S;
    rep(i, 0, n) {
        while(!S.empty() && S.back().first > w[i]) S.pop_back();
        if(!S.empty()) {
            auto p = S.back();
            add_pt(p.second, i);
        }
        S.push_back({w[i], i});
    }
    S.clear();
    for (int i = n - 1; i >= 0; i--)  {
        while(!S.empty() && S.back().first > w[i]) S.pop_back();
        if(!S.empty()) {
            auto p = S.back();
            add_pt(p.second, i);
        }
        S.push_back({w[i], i});
    }

    rep(i, 0, q) {
        int l, r; cin >> l >> r; l--, r--;
        qrs[l].push_back({r, i});
    }
    for (int i = n - 1; i >= 0; i--) {
        for (auto &p : upd[i]) {
            add(p.second, p.first);
        }
        for (auto &p : qrs[i]) {
            res[p.second] = get(p.first);
        }
    }
    rep(i, 0, q) cout << res[i] << '\n';


}