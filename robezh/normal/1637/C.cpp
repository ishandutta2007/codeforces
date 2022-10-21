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
    ll s = 0;
    ll res = 0;
    int odd = 0;
    rep(i, 0, n) {
        cin >> a[i];
        if(i != 0 && i != n - 1) {
            s += a[i];
            res += (a[i] + 1) / 2;
            odd += (a[i] == 1);
        }
    }
    if(odd == n - 2 || (n == 3 && a[1] % 2 == 1)) {
        cout << -1 << "\n";
        return ;
    }
    cout << res << '\n';



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