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

const int N = (int)1e6 + 50, INF = (int)1e9 + 50;
int n, m;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        int g = 0;
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, m) {
            int x; cin >> x;
            g = __gcd(x, g);
        }
        ll sum = 0;
        vi cnt(g, 0), mn(g, INF);
        rep(i, 0, n) {
            sum += abs(a[i]);
            if(a[i] < 0) cnt[i % g] ^= 1;
            mn[i % g] = min(mn[i % g], abs(a[i]));
        }
        ll res = -(ll)1e18;
        rep(f, 0, 2) {
            ll cur = sum;
            rep(i, 0, g) {
                if(cnt[i] == f) {
                    cur -= mn[i] * 2;
//                    cout << f << " "<< sum << " " << cur << endl;
                }
            }
//            cout << f << " "<< cur << endl;
            res = max(res, cur);
        }
        cout << res << '\n';
    }
}