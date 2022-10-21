#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;


int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        double sum = 0, mx = - 1e9 - 50;
        rep(i, 0, n) {
            int x; cin >> x;
            sum += x;
            mx = max(mx, (double)x);
        }
        cout << fixed << setprecision(10) << (sum - mx) / (n - 1) + mx << '\n';

    }
}