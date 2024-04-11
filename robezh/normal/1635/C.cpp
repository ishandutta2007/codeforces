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
typedef pair<int, int> P;

const int N = (int)2e5 + 50;

int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) cin >> a[i];
        if(a[n - 2] > a[n - 1]) {
            cout << "-1\n";
        } else if(a[n - 1] < 0) {
            if(is_sorted(a, a + n)) cout << 0 << '\n';
            else cout << -1 << '\n';
        } else {
            cout << n - 2 << '\n';
            rep(i, 0, n - 2) cout << i + 1 << " " << n - 1 << " " << n  << '\n';
        }
    }
}