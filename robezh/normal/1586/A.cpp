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
const int N = 105;

int n, a[N];

void solve() {
    cin >> n;
    int sum = 0;
    rep(i, 0, n) {
        cin >> a[i];
        sum += a[i];
    }
    bool gd = false;
    for (int i = 2; i < sum; i++) {
        if(sum % i == 0) gd = true;
    }
    if(gd) {
        cout << n << "\n";
        rep(i, 1, n + 1) cout << i << " " ;
        cout << '\n';
    } else {
        rep(i, 0, n) {
            if((sum - a[i]) % 2 == 0) {
                cout << n - 1 << "\n";
                rep(j, 0, n) {
                    if(j != i) cout << j + 1 << " ";
                }
                cout << '\n';
                return ;
            }
        }
        assert(false);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }

}