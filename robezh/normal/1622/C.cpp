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
typedef pair<ll, int> pli;
typedef vector<int> vi;

const int N = (int)2e5 + 50;
const ll INF = (ll)1e18;

int n, a[N];
ll k;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {

        cin >> n >> k;
        ll s = 0;
        rep(i, 1, n + 1) cin >> a[i], s += a[i];
        sort(a + 1, a + n + 1);
        if(s <= k) {
            cout << 0 << endl;
            continue;
        }

//        cout << s << endl;
        s = -a[1];
        ll res = INF;
        rep(i, 1, n + 1) {
            s += a[i];
            ll x = a[1] - ((k - s) - ((k - s) % (n - i + 1) + (n - i + 1)) % (n - i + 1)) / (n - i + 1);
//            cout << i << " " << (k - s) << " " << ((k - s) - (k - s) % (n - i + 1)) / (n - i + 1) << " " << max(0LL, x) << " " << (n - i) << endl;
            res = min(res, max(0LL, x) + (n - i));
        }
        cout << res << '\n';
    }
}