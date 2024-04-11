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

int n, m;
vector<vi> a;
vi cs[N], rs[N];

ll solve(vi &vs) {
    sort(all(vs));
    ll sum = 0, res = 0;
    rep(i, 0, sz(vs)) {
        res += 1LL * vs[i] * i - sum;
        sum += vs[i];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    a = vector<vi> (n, vi(m));


    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> a[i][j];
            cs[a[i][j]].push_back(i);
            rs[a[i][j]].push_back(j);
        }
    }
    ll res = 0;
    rep(i, 0, N) {
        res += solve(cs[i]) + solve(rs[i]);
    }
    cout << res << '\n';
}