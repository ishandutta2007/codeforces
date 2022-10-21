#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = (int)2e5 + 50;

int n, m;
ll a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n >> m;
    ll g = 0;
    rep(i, 0, n) {
        cin >> a[i];
        if(i) g = __gcd(abs(a[i] - a[i - 1]), g);
    }
//    cout << g << endl;
    rep(i, 0, m) cin >> b[i];
    rep(i, 0, m) cout << __gcd(g, b[i] + a[0]) << ' ';

}