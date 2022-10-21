#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
const int N = (int)1e5 + 50;

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

    ll get(int x) {
        ll res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
        return res;
    }
} bit[2];

int n, k, a[N];
map<int, int> mp;
const ll INF = (ll)1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> k;
        mp.clear();
        rep(i, 0, n) cin >> a[i], mp[a[i]]++;
        vector<pii> vs;
        vector<pii> ps;
        for(auto p : mp) {
            vs.push_back({p.second, p.first});
            ps.push_back(p);
        }
        sort(all(vs));
        bit[0].init((sz(vs)));
        bit[1].init((sz(vs)));
        rep(i, 0, sz(vs)) {
            bit[1].add(i, vs[i].first);
            bit[0].add(i, 1);
//            cout << i << " add " << vs[i].first << endl;
        }
        int pt = 0;
        ll res = INF;
        int emp = 0;
        rep(mex, 0, n + 1) {
            if(k < emp) break;
            int c = (pt < sz(ps) && ps[pt].first == mex ? ps[pt].second : 0);

            if(c) {
                int idx = lower_bound(all(vs), pii{ps[pt].second, ps[pt].first}) - vs.begin();
                bit[1].add(idx, -vs[idx].first);
                bit[0].add(idx, -1);

                pt++;
            } else {
                emp++;
            }

            if(c <= k) {
                int l = -1, r = sz(vs), mid;
                while(l + 1 < r) {
                    mid = (l + r) / 2;
                    if(bit[1].get(mid) <= k - c) l = mid;
                    else r = mid;
                }
//                cout << "max is " << l << " " << bit[1].get()endl;
                res = min(res, (mex + bit[0].get(sz(vs) - 1) - bit[0].get(l)) - mex);

//                cout << c << endl;
//                cout << mex << " " << bit[0].get(sz(vs) - 1) - bit[0].get(l) << ": " << endl;
            }
        }
        cout << res << '\n';
    }



}