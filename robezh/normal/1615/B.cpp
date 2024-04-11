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
const int N = (int)2e5 + 50, B = 18;

int psum[N][B];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    rep(i, 1, N) {
        rep(j, 0, B) {
            psum[i][j] = psum[i - 1][j] + (i >> j & 1);
        }
    }
    int T;
    cin >> T;
    while(T--) {
        int l, r; cin >> l >> r;
        int mx = 0;
        rep(i, 0, B) {
            mx = max(mx, psum[r][i] - psum[l - 1][i]);
        }
        cout << (r - l + 1 - mx) << '\n';
    }

}