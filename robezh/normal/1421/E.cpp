#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50;
const ll INF = (ll)1e18;

int n;
pii a[N];
ll psum[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 1, n + 1) {
        cin >> a[i].first; a[i].second = i;
    }
    if(n == 1) {
        cout << a[1].first << endl;
        return 0;
    }
    sort(a + 1, a + n + 1, greater<>());
    rep(i, 1, n + 1) {
        psum[i] = psum[i - 1] + a[i].first;
    }
    int s = (n % 3 == 1 ? 1 : 2 - n % 3);
    ll res = -INF;
    for(int i = s; i <= n; i += 3) {
        if(i * 2 - 1 == n) {
            bool c = true;
            for(int j = 1; j <= i; j++) if(a[j].second % 2 == 0) c = false;
            if(!c) res = max(res, 2 * psum[i] - psum[n]);
            else res = max(res, 2 * psum[i] - psum[n] - 2 * a[i].first + 2 * a[i + 1].first);
        } else {
            res = max(res, 2 * psum[i] - psum[n]);
        }
    }
    cout << res << '\n';

}