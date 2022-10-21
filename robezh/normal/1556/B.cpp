#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)1e5 + 50;
const ll INF = (ll)1e18;

int n;
int a[N];
vi c[2];

int bit[N];


void add(int x, int val) {
    for(int i = x; i < n; i |= i + 1) bit[i] += val;
}

ll get(int x) {
    ll res = 0;
    for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
    return res;
}

int pos[N];

ll solve(vi vs) {
    fill(bit, bit + n, 0);
    rep(i, 0, n) add(i, 1);
    rep(i, 0, n) pos[vs[i]] = i;
    ll res = 0;
    rep(i, 0, n) {
        res += get(pos[i] - 1);
        add(pos[i], -1);
    }
    return res;
}


vi create(int f) {
    int b = f;
    int pt[2] = {0, 0};
    vi res;
    while(pt[b] < sz(c[b])) {
        res.push_back(c[b][pt[b]++]);
        b ^= 1;
    }
//    cout << sz(c[0]) << " " << sz(c[1]) << " " << sz(res) << endl;
    assert(sz(res) == n);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        c[0].clear();
        c[1].clear();
        rep(i, 0, n) {
            cin >> a[i];
            c[a[i] % 2].push_back(i);
        }
        ll res = INF;
        if(sz(c[0]) == sz(c[1]) + 1 || sz(c[0]) == sz(c[1])) res = min(res, solve(create(0)));
        if(sz(c[0]) == sz(c[1]) - 1 || sz(c[0]) == sz(c[1])) res = min(res, solve(create(1)));
        if(res == INF) res = -1;
        cout << res << '\n';

    }
}