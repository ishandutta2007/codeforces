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
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int a, b, c, d; cin >> c >> d;
//        c -= a, d -= b;
        if((c + d) % 2 != 0) cout << -1 << '\n';
        else {
            if(c == 0 && d == 0) cout << 0 << '\n';
            else cout << ((c == d || c == -d) ? 1 : 2) << '\n';
        }
    }
}