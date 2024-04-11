#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)105;

int n, a[N], b[N], c[N];
int res[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n) cin >> b[i];
        rep(i, 0, n) cin >> c[i];
        res[0] = a[0];
        rep(i, 1, n - 1) {
            res[i] = (res[i - 1] == a[i] ? b[i] : a[i]);
        }
        int ea = (res[n - 2] == a[n - 1] || res[0] == a[n - 1]);
        int eb = (res[n - 2] == b[n - 1] || res[0] == b[n - 1]);
        int ec = (res[n - 2] == c[n - 1] || res[0] == c[n - 1]);
        if(!ea) res[n - 1] = a[n - 1];
        if(!eb) res[n - 1] = b[n - 1];
        if(!ec) res[n - 1] = c[n - 1];
        rep(i, 0, n) cout << res[i] << " ";
        cout << '\n';
    }

}