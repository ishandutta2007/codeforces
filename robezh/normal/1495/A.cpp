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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vi xs, ys;
        rep(i, 0, 2 * n) {
            int x, y; cin >> x >> y;
            x = abs(x), y = abs(y);
            if(x == 0) ys.push_back(y);
            else xs.push_back(x);
        }
        sort(all(xs));
        sort(all(ys));
        double res = 0;
        rep(i, 0, n) res += hypot(xs[i], ys[i]);
        cout << fixed << setprecision(15) << res << '\n';
    }


}