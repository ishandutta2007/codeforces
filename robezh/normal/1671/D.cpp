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

    const int N = (int)2e5 + 50, INF = (int)1e9;

    int n, x, a[N];

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int T;
        cin >> T;
        while(T--) {
            cin >> n >> x;
            int mn = INF, mx = -INF;
            ll res = 0;
            rep(i, 0, n) {
                cin >> a[i];
                mn = min(mn, a[i]);
                mx = max(mx, a[i]);
                if(i) res += abs(a[i] - a[i - 1]);
            }
            if(1 < mn) {
                int r0 = min(a[0] - 1, a[n - 1] - 1);
                rep(i, 1, n) {
                    r0 = min(r0, min(a[i - 1], a[i]) * 2 - 2);
                }
                res += r0;
            }
            if(x > mx) {
                int r0 = min(x - a[0], x - a[n - 1]);
                rep(i, 1, n) {
                    r0 = min(r0, 2 * x - 2 * max(a[i - 1], a[i]));
                }
                res += r0;
            }
            cout << res << '\n';
        }
    }