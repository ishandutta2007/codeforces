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
const int N = 50005, LOGN = 17;

int n, x, a[N];
ll v[N];

struct RMQ {
    int n;
    int mm[N];
    ll st[LOGN][N];

    void build() {
        mm[0]=-1;
        for(int i = 1; i <= n; i++) mm[i]= (i & (i-1)) == 0 ? mm[i-1] + 1 : mm[i-1];
        for(int i = 0; i < n; i++){
            st[0][i] = v[i];
        }
        for(int lg = 1; lg < LOGN; lg++){
            for(int j = 0; j + (1 << lg) - 1 < n; j++){
                st[lg][j] = min(st[lg-1][j], st[lg-1][j+(1<<(lg-1))]);
            }
        }
    }

    ll rmq(int l, int r){
        int k = mm[r - l + 1];
        return min(st[k][l], st[k][r-(1<<k)+1]);
    }
} rmq;




int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 1, n + 1) cin >> a[i];
        cin >> x;
        v[0] = 0;
        ll s = 0;
        rep(i, 1, n + 1) {
            s += a[i];
            v[i] = s - 1LL * x * i;
        }
        rmq.n = n + 1;
        rmq.build();
        vector<pii> vs;
        for (int i = 0; i + 2 <= n; i++) {
            if(rmq.rmq(i + 2, n) >= v[i]) continue;
            int l = i + 1, r = n, mid;
            while(l + 1 < r) {
                mid = (l + r) / 2;
                if(rmq.rmq(i + 2, mid) < v[i]) r = mid;
                else l = mid;
            }
            vs.push_back({i + 1, r});
        }
        int res = 0;
        while(!vs.empty()) {
            int val = vs.back().first; vs.pop_back();
            res++;
            while(!vs.empty() && val <= vs.back().second) vs.pop_back();
        }
        cout << n - res << '\n';

    }


}