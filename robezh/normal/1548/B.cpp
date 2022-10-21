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
const int N = (int)2e5 + 50, LOGN = 18;

int n;
ll a[N];

struct RMQ {
    int n;
    ll st[LOGN][N];
    int mm[N];

    void build(int _n) {
        n = _n;
        mm[0]=-1;
        for(int i = 1; i <= n; i++) mm[i]= (i & (i-1)) == 0 ? mm[i-1] + 1 : mm[i-1];
        for(int i = 0; i < n; i++){
            st[0][i] = abs(a[i + 1] - a[i]);
        }
        for(int lg = 1; lg < LOGN; lg++){
            for(int j = 0; j + (1 << lg) - 1 < n; j++){
                st[lg][j] = __gcd(st[lg-1][j], st[lg-1][j+(1<<(lg-1))]);
            }
        }
    }

    ll rmq(int l, int r){
        int k = mm[r - l + 1];
        return __gcd(st[k][l], st[k][r-(1<<k)+1]);
    }
} rmq;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) cin >> a[i];
        rmq.build(n - 1);
        int r = 0;
        int res = 1;
        rep(i, 0, n - 1) {
            r = max(r, i);
            while(r < n - 1 && rmq.rmq(i, r) > 1) r++;
            res = max(res, r - i + 1);
        }
        cout << res << '\n';
    }

}