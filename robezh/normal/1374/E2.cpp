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

const ll INF = (ll)1e18 + 50;
int n, k, m;
vector<pii> c, a, b, d;

struct BIT {
    static const int N = (int)1e4 + 50;

    int bit[N];
    void clear() {
        memset(bit, 0, sizeof(bit));
    }

    void add(int x, int val) {
        for(int i = x; i < N; i |= i + 1) bit[i] += val;
    }

    int get(int x) {
        ll res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
        return res;
    }
} cnts, sums;

set<int> S[(int)1e4 + 50];
int lim, rem;

ll topk(int k) {
    if(k < 0) return INF;
    if(cnts.get(cnts.N - 1) < k) return INF;
    int l = 0, r = cnts.N - 1, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(cnts.get(mid) >= k) r = mid;
        else l = mid;
    }
    lim = r, rem = (cnts.get(r) - k);
    return sums.get(r) - (cnts.get(r) - k) * r;
}

void add(pii p, int d) {
    cnts.add(p.first, d);
    sums.add(p.first, d * p.first);
    if(d == 1) {
        S[p.first].insert(p.second);
    }
    else S[p.first].erase(p.second);
}

ll mnres = INF;
ll fres = -1;

void check(ll cursum, int cr, int ar) {
    mnres = min(mnres, cursum + topk(m - cr - ar * 2));
    if(mnres == fres) {
        cout << fres << '\n';
        for(int i = 0; i < cr; i++) cout << c[i].second + 1 << " ";
        for(int i = 0; i < ar; i++) cout << a[i].second + 1 << " ";
        for(int i = 0; i < ar; i++) cout << b[i].second + 1 << " ";
//        cout << endl;
        for(int i = 0; i < lim; i++) for(int x : S[i]) cout << x + 1 << " ";
        int cnt = 0;
        for(int x : S[lim]) if(cnt++ >= rem) cout << x + 1 << " ";
        cout << '\n';
//        cout << "lim: " << lim << endl;
        exit(0);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    rep(i, 0, n) {
        int t, x, y; cin >> t >> x >> y;
        if(x && y) c.push_back({t, i});
        else if(x) a.push_back({t, i});
        else if(y) b.push_back({t, i});
        else d.push_back({t, i});
    }
    sort(all(a));
    sort(all(b));
    sort(all(c));
    if(min(sz(a), sz(b)) + sz(c) < k) return cout << "-1" << endl, 0;
    for(int it = 0; it < 2; it++) {
        mnres = INF;
        int ar = min(k, min(sz(a), sz(b)));
        int cr = k - ar;
        sums.clear(), cnts.clear();
        for(int i = 0; i < (int)1e4 + 1; i++) S[i].clear();
        rep(i, ar, sz(a)) add(a[i], 1);
        rep(i, ar, sz(b)) add(b[i], 1);
        rep(i, cr, sz(c)) {
            add(c[i], 1);
        }
        rep(i, 0, sz(d)) add(d[i], 1);
        ll cursum = 0;
        rep(i, 0, ar) cursum += a[i].first + b[i].first;
        rep(i, 0, cr) cursum += c[i].first;

        check(cursum, cr, ar);
        while(cr < sz(c) && ar > 0) {
            add(c[cr], -1);
            cursum += c[cr].first;
            cr++;
            ar--;
            add(a[ar], 1);
            add(b[ar], 1);
            cursum -= a[ar].first + b[ar].first;
            check(cursum, cr, ar);
        }
        if(it == 0) {
            fres = mnres;
            if(mnres == INF) {
                cout << -1 << endl;
                return 0;
            }
        }
//        cout << mnres << endl;
    }
}