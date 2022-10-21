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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int x, y; cin >> x >> y;
        ll res = 0;
        rep(k, 1, 100000) {
//            cout << k <<  y << " " << x / k - 1 << endl;
            res += max(max(min(y, x / k - 1), 0) - k, 0);
        }
        cout << res << '\n';
    }

}