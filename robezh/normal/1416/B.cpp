#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)1e4 + 50;

struct P {
    int i, j;
    ll x;
};

ll n, a[N], b[N];

ll grem(ll x, ll d) {
    return (x % d + d) % d;
}

ll dceil(int x, int d) {
    return (x % d == 0 ? x : x / d * d + d);
}

vector<P> res;

void add(int i, int j, ll x) {
    res.push_back({i, j, x});
    a[i] -= x * i;
    a[j] += x * i;
}

void solve() {
    cin >> n;
    ll sum = 0;
    rep(i, 1, n + 1) cin >> a[i], sum += a[i];
    if(sum % n != 0) {
        cout << -1 << "\n";
        return ;
    }
    ll av = sum / n;
    res.clear();
    for(int i = 2; i <= n; i++) {
        ll want = dceil(a[i], i) - a[i];
//        cout << i << " want " << want << endl;
        add(1, i, want);
        assert(a[i] % i == 0);
        add(i, 1, a[i] / i);
    }
    for(int i = 2; i <= n; i++) {
        add(1, i, av);
    }
    cout << res.size() << '\n';
    for(auto p : res) cout << p.i << " " << p.j << " " << p.x << '\n';
    rep(i, 1, n + 1) {
        assert(a[i] == av);
    }
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