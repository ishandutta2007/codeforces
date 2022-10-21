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
const int N = (int)6e5 + 50;
const ll INF = (ll)1e18;

int n, w, a[N], b[N];
vector<pii> vs;

struct BIT {
    int n;
    ll bit[N];

    void add(int x, ll val) {
        for(int i = x; i < n; i |= i + 1) bit[i] += val;
    }

    ll get(int x) {
        ll res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
        return res;
    }
} bit[2];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> w;
    rep(i, 0, n) {
        cin >> a[i] >> b[i];
        b[i] -= a[i];
        vs.push_back({a[i], i * 2});
        vs.push_back({b[i], i * 2 + 1});
    }
    sort(all(vs));
    bit[0].n = bit[1].n = 2 * n;
    vi idx(n);
    iota(all(idx), 0);
    sort(all(idx), [&](const int i, const int j) {
        return a[i] + b[i] < a[j] + b[j];
    });
    rep(i, 0, n) {
        int loc = lower_bound(all(vs), pii{a[i], i * 2}) - vs.begin();
        bit[0].add(loc, 1);
        bit[1].add(loc, a[i]);
    }
    ll res = INF, sum = 0;
    int mxj = -1;
    for (int j = 0; j <= n; j++) {
        int i = idx[j];
//        cout << bit[0].get(2 * n + 1) << "\n";
        if(j + n >= w) {

            int l = -2, r = 2 * n - 1, mid;
            while(l + 1 < r) {
                mid = (l + r) / 2;
                if(bit[0].get(mid) + j >= w) r = mid;
                else l = mid;
            }
//            cout << j << ": " << sum << " " << bit[1].get(r) << endl;
//            res = min(res, sum + bit[1].get(r));
            ll cres = sum + bit[1].get(r);
            if(cres < res) {
                res = cres;
                mxj = j;
            }
        }
        if(j == n) break;
        int i0 = lower_bound(all(vs), pii{a[i], i * 2}) - vs.begin();
        bit[0].add(i0, -1);
        bit[1].add(i0, -a[i]);
        int i1 = lower_bound(all(vs), pii{b[i], i * 2 + 1}) - vs.begin();
        bit[0].add(i1, 1);
        bit[1].add(i1, b[i]);
        sum += a[i];
    }
    cout << res << '\n';
    vi rs(n, 0);
    vector<pii> vals;
    rep(j, 0, n) {
        int i = idx[j];
        if(j < mxj) {
            rs[i]++;
            vals.push_back({b[i], i});
        } else {
            vals.push_back({a[i], i});
        }
    }
    sort(all(vals));
    rep(i, 0, w - mxj) rs[vals[i].second]++;
    rep(i, 0, n) cout << rs[i];
    cout << '\n';
}