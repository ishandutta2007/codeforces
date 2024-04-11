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
typedef vector<ll> vl;
const int N = 4005;
const ll INF = (ll)1e18;

int a[N];
int n, m;

vl solve(int l, int r) {
    if(l > r) return {0};
    int pos = min_element(a + l, a + r + 1) - a;
    vl L = solve(l, pos - 1);
    vl R = solve(pos + 1, r);

    vl res(sz(L) + sz(R), -INF);
    rep(i, 0, sz(L)) {
        rep(j, 0, sz(R)) {
            res[i + j] = max(res[i + j], L[i] + R[j] - 1LL * a[pos] * i * j * 2);
            int len = i + j + 1;
            res[i + j + 1] = max(res[i + j + 1], L[i] + R[j] + 1LL * a[pos] * (m - (len * len - i * i - j * j)));
        }
    }
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, n) cin >> a[i];
    vl vs = solve(0, n - 1);
//    for (ll x : vs) cout << x << " ";
//    cout << endl;
    cout << vs[m] << '\n';
}