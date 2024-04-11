#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;
const int N = (int)5e5 + 50;
const ll INF = (ll)1e18;

int n, m;
ll a[N], x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    m = (n + 1) / 2;
    for(int i = 0; i < m; i++) cin >> a[i];
    cin >> x;
    if(x >= 0) {
        ll sum = 0;
        for(int i = 0; i < m; i++) sum += a[i];
        if(sum + 1LL * x * (n - m) > 0) cout << n << '\n';
        else cout << -1 << "\n";
        return 0;
    } else {
        for(int i = m - 1; i >= 0; i--) a[i] += a[i + 1];
        ll mx_k = INF;
        for(int i = 0; i < m; i++) {
            if(a[i] <= 0) return cout << -1 << endl, 0;
            mx_k = min(mx_k, (m - i) + (a[i] - 1) / (-x));
//            cout << i << ": " << mx_k << ", " << (m - i) + (a[i] - 1) / (-x) << endl;
            if(mx_k >= n - i) return cout << n - i << endl, 0;
        }
        return cout << -1 << endl, 0;
    }

}