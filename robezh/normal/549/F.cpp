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

const int N = (int)3e5 + 50, LOGN = 19;

struct RMQ {
    int n;
    int mm[N];
    pii st[LOGN][N];

    void build(pii x[], int _n) {
        n = _n;
        mm[0]=-1;
        for(int i = 1; i <= n; i++) mm[i]= (i & (i-1)) == 0 ? mm[i-1] + 1 : mm[i-1];
        for(int i = 0; i < n; i++){
            st[0][i] = x[i];
        }
        for(int lg = 1; lg < LOGN; lg++){
            for(int j = 0; j + (1 << lg) - 1 < n; j++){
                st[lg][j] = max(st[lg-1][j], st[lg-1][j+(1<<(lg-1))]);
            }
        }
    }

    pii rmq(int l, int r){
        int k = mm[r - l + 1];
        return max(st[k][l], st[k][r-(1<<k)+1]);
    }
} rmq;


int n, k;
int a[N], s[N];
pii b[N];

int idx[N];
unordered_map<int, int> mp[N];
ll res = 0;

int unite(int u, int v, int val) {
    if(sz(mp[u]) > sz(mp[v])) swap(u, v);
    for (auto &pr : mp[u]) {
        int nval = u < v ? (pr.first + val) % k : (pr.first - val) % k;
        if(nval < 0) nval += k;
//        cout << "finding " << nval << " in " << v << " sz " << sz(mp[v]) << endl;
        auto it = mp[v].find(nval);
        if(it != mp[v].end()) {
            res += 1LL * it->second * pr.second;
//            cout << v << " " << it->second << endl;
        }
    }
    for (auto &pr : mp[u]) {
        mp[v][pr.first] += pr.second;
//        cout << "added " << v << " " <<  mp[v][pr.first] << endl;
    }
    return v;
}

int solve(int l, int r) {
    if(l == r) return l;
    int mid = rmq.rmq(l + 1, r).second;
    int vl = solve(l, mid - 1), vr = solve(mid, r);
//    cout << l << " " << r << endl;

    vl = unite(vl, vr, a[mid]);
    return vl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    rep(i, 1, n + 1) {
        cin >> a[i];
        s[i] = (s[i - 1] + a[i]) % k;
        b[i] = {a[i], i};
    }
    rmq.build(b, n + 1);

    rep(i, 0, n + 1) {
        idx[i] = i;
        mp[i][s[i]] = 1;
    }
    solve(0, n);
    cout << res - n << endl;



}