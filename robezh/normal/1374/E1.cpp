#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

int n, k;
vi c, a, b, pc, pa, pb;

vi getpre(vi &xs) {
    vi res(sz(xs));
    for(int i = 0; i < sz(xs); i++) {
        res[i] = xs[i];
        if(i > 0) res[i] += res[i - 1];
    }
    return res;
}

const int INF = (int)2e9 + 50;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    c.clear(), pc.clear(), a.clear(), b.clear(), pa.clear(), pb.clear();
    rep(i, 0, n) {
        int t, x, y; cin >> t >> x >> y;
        if(x && y) c.push_back(t);
        else if(x) a.push_back(t);
        else if(y) b.push_back(t);
    }
    sort(all(a));
    sort(all(b));
    sort(all(c));
    pa = getpre(a);
    pb = getpre(b);
    pc = getpre(c);
    int res = INF;
    for(int i = 0; i <= k; i++) {
        if(i > sz(pa) || i > sz(pb) || k - i > sz(pc)) continue;
        res = min(res, (i == 0 ? 0 : pa[i - 1] + pb[i - 1]) + (k - i == 0 ? 0 : pc[k - i - 1]));
    }
    if(res == INF) res = -1;
    cout << res << "\n";


}