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

void solve() {
    int n;
    cin >> n;
    vi p(n);
    vector<vi> pos(n);
    rep(i, 0, n) {
        cin >> p[i]; p[i]--;
        pos[p[i]].push_back(i);
    }
    vi idx(n, 0);
    iota(all(idx), 0);
    sort(all(idx), [&](const int i, const int j) {
        return sz(pos[i]) < sz(pos[j]);
    });
    rep(it, 0, n) {
        int i = idx[it];
        while(!pos[i].empty()) {
            vi vs;
            rep(j, it, n) {
                int ci = idx[j];
                vs.push_back(pos[ci].back());
                pos[ci].pop_back();
            }
//            for (int x : vs) cout << x << " ";
//            cout << endl;
            rep(j, 0, sz(vs) - 1) {
                swap(p[vs[j]], p[vs[j + 1]]);
            }
        }
    }
    rep(i, 0, n) cout << p[i] + 1 << " ";
    cout << "\n";
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