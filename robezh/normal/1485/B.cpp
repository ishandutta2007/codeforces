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
const int N = (int)1e5 + 50;

int n, q, k;
int a[N], psum[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q >> k;
    rep(i, 0, n) cin >> a[i];
    while(q--) {
        int l, r; cin >> l >> r; l--, r--;
        cout << 2 * k - 2 * (r - l + 1) - (a[l] - 1) - (k - a[r]) << '\n';
    }

}