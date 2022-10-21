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

int n;
int a[N];

void solve() {
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
    }
    int mx = -1;
    rep(i, 0, n) {
        if(mx > a[i]) {
            cout << "YES\n";
            return ;
        }
        mx = max(mx, a[i]);
    }
    cout << "NO\n";
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