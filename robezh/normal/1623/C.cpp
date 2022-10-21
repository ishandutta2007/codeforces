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
const int N = (int)2e5 + 50;

int n, h[N];
ll v[N];

bool check(int mn) {
    rep(i, 0, n) v[i] = h[i];
    for (int i = n - 1; i >= 0; i--) {
        if(v[i] < mn) return false;
        if(i >= 2) {
            ll mxgive = min(v[i] - mn, (ll)h[i]);
            v[i - 2] += mxgive / 3 * 2;
            v[i - 1] += mxgive / 3;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) cin >> h[i];

        int l = 0, r = (int)1e9 + 50, mid;
        while(l + 1 < r) {
            mid = (l + r) / 2;
            if(check(mid)) l = mid;
            else r = mid;
        }
        cout << l << '\n';
    }

}