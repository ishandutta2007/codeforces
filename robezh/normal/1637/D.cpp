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

const int N = 105;

int n, a[N], b[N];

void solve() {
    cin >> n;
    ll sqsum = 0;
    int sum = 0;
    rep(i, 0, n) {
        cin >> a[i], sqsum += a[i] * a[i];
        sum += a[i];
    }
    rep(i, 0, n) {
        cin >> b[i], sqsum += b[i] * b[i];
        sum += b[i];
    }
    vi good(sum + 1, 0);
    good[0] = 1;
    rep(i, 0, n) {
        vi ngood(sum + 1, 0);
        for (int j = sum; j >= a[i]; j--) ngood[j] |= good[j - a[i]];
        for (int j = sum; j >= b[i]; j--) ngood[j] |= good[j - b[i]];
        good = ngood;
    }
    ll best = (ll)1e18;
    rep(i, 0, sum + 1) {
        if(good[i]) {
//            cout << "g " << i << endl;
            best = min(best, 1LL * i * i + (sum - i) * (sum - i));
        }
    }
//    cout << sqsum << endl;
    cout << best + (n - 2) * sqsum << "\n";

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