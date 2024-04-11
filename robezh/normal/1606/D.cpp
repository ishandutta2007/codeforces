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

int n, m;
struct P {
    int mxl, mnl, mxr, mnr, idx;
};

void solve() {
    cin >> n >> m;
    vector<vi> a(n, vi(m, 0));
    rep(i, 0, n) {
        rep(j, 0, m) cin >> a[i][j];
    }
    vector<vi> pmax(all(a)), pmin(all(a)), smax(all(a)), smin(all(a));
    rep(i, 0, n) {
        rep(j, 1, m) {
            pmax[i][j] = max(pmax[i][j - 1], pmax[i][j]);
            pmin[i][j] = min(pmin[i][j - 1], pmin[i][j]);
        }
        for (int j = m - 2; j >= 0; j--) {
            smax[i][j] = max(smax[i][j + 1], smax[i][j]);
            smin[i][j] = min(smin[i][j + 1], smin[i][j]);
        }
    }
    rep(j, 0, m - 1) {
        vector<P> ps;
        rep(i, 0, n) {
            ps.push_back({pmax[i][j], pmin[i][j], smax[i][j + 1], smin[i][j + 1], i});
        }
        sort(all(ps), [](const P &p1, const P &p2) {
            return p1.mxl < p2.mxl;
        });
        for (int i = n - 2; i >= 0; i--) {
            ps[i].mnl = min(ps[i].mnl, ps[i + 1].mnl);
            ps[i].mxr = max(ps[i].mxr, ps[i + 1].mxr);
        }
        rep(i, 1, n) ps[i].mnr = min(ps[i].mnr, ps[i - 1].mnr);

        rep(i, 0, n - 1) {
            if(ps[i].mxl < ps[i + 1].mnl && ps[i].mnr > ps[i + 1].mxr) {
                vi res(n, 0);
                rep(k, 0, i + 1) res[ps[k].idx] = 1;
                cout << "YES\n";
                rep(k, 0, n) cout << (res[k] ? "B" : "R");
                cout << " " << j + 1 << "\n";
                return ;
            }
        }
    }
    cout << "NO\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}