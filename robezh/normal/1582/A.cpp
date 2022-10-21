#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        ll a, b, c;
        cin >> a >> b >> c;
        int u = 24;
        if(a > u / 1) a -= (a - u / 1) / 2 * 2;
        if(b > u / 2) b -= (b - u / 2) / 2 * 2;
        if(c > u / 3) c -= (c - u / 3) / 2 * 2;
        ll res = 6;
        rep(i, 0, a + 1) {
            rep(j, 0, b + 1) {
                rep(k, 0, c + 1) {
                    res = min(res, abs((2 * i - a) + (2 * j - b) * 2 + (2 * k - c) * 3));
                }
            }
        }
        cout << res << '\n';

    }



}