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
const int N = 1005;

int n, c[N];
ll smnd[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);



    cin >> n;
    rep(i, 0, n) cin >> c[i];
    ll res = 0;

    for (int i = n - 1; i >= 0; i--) {
        ll csum = 0, mnd = 0;
        for (int j = i; j >= 0; j--) {
            if(j % 2 == 0) csum -= c[j];
            else csum += c[j];
            mnd = min(mnd, csum);
            smnd[j][i] = mnd;
        }
    }

    rep(i, 1, n) {
        if(i % 2 == 0) continue;
        ll mnd = 0, cursum = 0;
        rep(j, i, n) {
            if(j % 2 == 1) {
                ll mnL = max(1LL, -mnd);
                ll mxL = c[i - 1];
                ll mnR = max(1LL, -smnd[i][j - 1]);
                ll mxR = c[j];
//                cout << mnL << " " << mxL << " " << mnR << " " << mxR << " " << cursum << " " << mnd << " " << endl;
//                cout << i << " " << j << ": " << max(0LL, min(mxL, mxR - cursum) - max(mnL, mnR - cursum) + 1) << endl;
                res += max(0LL, min(mxL, mxR - cursum) - max(mnL, mnR - cursum) + 1);
            }
            if(j % 2 == 1) cursum -= c[j], mnd = min(mnd, cursum);
            else cursum += c[j];
        }
    }
    cout << res << '\n';


}