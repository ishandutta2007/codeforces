#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
const int N = (int)2e5 + 50;

int n;

struct BIT {
    int n, bit[N];
    void add(int x, int val) {
        for (int i = x; i < n; i |= i + 1) bit[i] = max(bit[i], val);
    }

    int get(int x) {
        int res = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) res = max(res, bit[i]);
        return res;
    }
} bit;

typedef pair<ll, ll> pll;

int v;
int t[N], a[N];
vector<pll> ps;
vector<ll> xs;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> v;
    rep(i, 0, n) {
        cin >> t[i];
        t[i] = (int)1e9 + 1 - t[i];
    }
    rep(i, 0, n) cin >> a[i];
    ll A0 = 1LL * ((int)1e9 + 1) * v;
    pll f = {A0, A0};
    ps.push_back(f);
    xs.push_back(A0);
    rep(i, 0, n) {
        ll A = 1LL * t[i] * v, B = a[i];
        ps.push_back({A - B, A + B});
//        cout << A - B << ", " << A + B << endl;
        xs.push_back(A + B);
    }
    sort(all(ps));
    sort(all(xs));
    xs.resize(unique(all(xs)) - xs.begin());
    bit.n = sz(xs);
    int res = 0;
    for (auto &p : ps) {
//        cout << p.first << " " << p.second << endl;
        auto idx = lower_bound(all(xs), p.second) - xs.begin();
        int cur = bit.get(idx) + 1;
        if(p == f) {
            res = max(res, cur);
        }
        bit.add(idx, cur);
    }
    cout << res - 1 << '\n';

}