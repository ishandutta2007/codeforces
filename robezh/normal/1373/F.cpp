#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)1e6 + 50;

int n;
ll a[N], b[N];

bool solve() {
    cin >> n;
    ll suma = 0, sumb = 0;
    rep(i, 0, n) cin >> a[i], suma += a[i];
    rep(i, 0, n) cin >> b[i], sumb += b[i];
    if(suma > sumb) return false;
    ll mxsum = 0;
    for(int i = 2 * n - 1; i >= 0; i--) {
        if(mxsum > b[i % n]) return false;
        mxsum = max(0LL, mxsum + a[i % n] - b[i % n]);
    }
    return true;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}