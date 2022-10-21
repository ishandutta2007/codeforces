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
const int N = (int)1e5 + 50;

struct up {
    int val, idx;
};

struct frac {
    ll first, second;
};

bool operator < (const frac &f1, const frac &f2) {
    return f1.first * f2.second < f2.first * f1.second;
}

int tp[N], id[N];
typedef pair<frac, int> P;

int n, k, m, a[N];
vector<up> us[N][4];
vector<P> ps;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
//    __int128 w;

    cin >> n >> m >> k;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) {
        int t, idx, b;
        cin >> t >> idx >> b; idx--;
        tp[i] = t;
        id[i] = idx;
        us[idx][t].push_back({b, i});
    }
    rep(i, 0, n) {
        int mx = -1;
        rep(j, 0, sz(us[i][1])) {
            if(us[i][1][j].val > a[i] && (mx == -1 || us[i][1][j].val > us[i][1][mx].val)) mx = j;
        }
        if(mx != -1) us[i][2].push_back({us[i][1][mx].val - a[i], us[i][1][mx].idx});
        rep(b, 2, 4) {
            sort(all(us[i][b]), [](const up &u1, const up &u2) {
                return u1.val > u2.val;
            });
        }
        ll csum = a[i];
        for (auto &u : us[i][2]) {
            ps.push_back({{u.val, csum}, u.idx});
            csum += u.val;
        }
        for (auto &u : us[i][3]) {
            ps.push_back({{u.val - 1, 1}, u.idx});
        }
    }
    sort(all(ps), [](const P &p1, const P &p2) {
        auto &f1 = p1.first, &f2 = p2.first;
        return f1.first * f2.second > f2.first * f1.second;
    });
//    for(auto p : ps) cout << id[p.second] << " add " << p.first.first << "/" << p.first.second << ", id: " << p.second << endl;
    vi res;
    rep(i, 0, min(sz(ps), k)) {
        res.push_back(ps[i].second);
    }
    sort(all(res), [&](const int i, const int j) {
        if(id[i] != id[j]) return id[i] < id[j];
        if(tp[i] != tp[j]) return tp[i] < tp[j];
        return false;
    });
    cout << sz(res) << "\n";
    for (int x : res) cout << x + 1 << ' ';
    cout << endl;



}