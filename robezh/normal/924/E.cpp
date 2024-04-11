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

const int N = (int)1e5 + 2;
typedef bitset<N> bst;

int n, l, r;
int val[N], t[N];
vi as, bs;
vi ps;
bst dp[2];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l >> r;
    rep(i, 0, n) cin >> val[i];
    rep(i, 0, n) cin >> t[i];
    rep(i, 0, n) {
        (t[i] ? as : bs).push_back(val[i]);
    }
    sort(all(as));
    int res = 0;
    dp[0][0] = 1;
    for (int b : bs) {
        dp[0] |= dp[0] << b;
        dp[1] |= dp[1] << b;
    }
    int sum = 0;
    for (int a : as) sum += a;

    for (int i = sz(as) - 1; i >= -1; i--) {
        if((int)(l == 0 ? dp[0]._Find_first() : dp[0]._Find_next(l - 1)) <= r - sum) {
            res = max(res, i + 1);
        }
        if((int)(l == 0 ? dp[1]._Find_first() : dp[1]._Find_next(l - 1)) <= r - sum)
            res = max(res, i + 2);
        if(i >= 0) {
            dp[1] |= dp[0] | (dp[1] << as[i]);
            dp[0] |= dp[0] << as[i];
            sum -= as[i];
        }
//        cout << i << endl;
//        rep(j, 0, N) if(dp[j][0]) cout << j << " ";
//        cout << endl;
//        rep(j, 0, N) if(dp[j][1]) cout << j << " ";
//        rep(j, 0, N) if(dp[j][1]) cout << j << " ";
//        cout << endl;
    }
    cout << res << '\n';


}