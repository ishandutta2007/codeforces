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

const int N = (int)2e5 + 50;
const ll INF = (ll)1e18;

int n;
int a[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) cin >> a[i];
        sort(a, a + n);
        ll sum = 0;
        rep(i, 0, n) sum += a[i];

        ll res = -INF;
        if(sum + 1LL * (n - 2) * a[n - 1] >= 0 && sum + 1LL * (n - 2) * a[0] <= 0) {
            ll s = 0, k = 0;
            rep(i, 0, n - 1) s += 1LL * a[i] * a[n - 1], k += (a[i] + a[n - 1]);
            res = max(res, 1LL * (-a[n - 1]) * k + s);
            for (int i = n - 2; i >= 1; i--) {
                s += 1LL * a[i] * (a[0] - a[n - 1]);
                k += a[0] - a[n - 1];
                res = max(res, 1LL * (-a[i]) * k + s);
            }
            cout << res << '\n';

        } else {
            cout << "INF\n";
        }

    }

}