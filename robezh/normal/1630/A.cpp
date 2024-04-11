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

int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> k;
        if(k < n - 1) {
            cout << k << " " << n - 1 << '\n';
            if(k != 0) cout << 0 << " " << n - 1 - k << '\n';
            rep(i, 1, n / 2) {
                if(i == k || i == n - 1 - k) continue;
                cout << i << " " << n - 1 - i << '\n';
            }
        } else {
            if(n == 4) cout << -1 << '\n';
            else {
                cout << n - 2 << " " << n - 1 << '\n';
                cout << 0 << " " << 1 << '\n';
                cout << 2 << " " << n - 4 << '\n';
                cout << 3 << " " << n - 3 << '\n';
                rep(i, 4, n / 2) cout << i << " " << n - 1 - i << '\n';
            }
        }
    }

}