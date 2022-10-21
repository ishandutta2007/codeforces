#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50;
const ll INF = (ll)1e18;

int n, m;
int x, k, y;
int a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> x >> k >> y;
    rep(i, 0, n) cin >> a[i];
    a[n++] = 0;
    rep(i, 0, m) cin >> b[i];
    b[m++] = 0;

    int cur = 0;
    ll fres = 0;
    for(int i = 0; i < m; i++) {
        int mx = -1, len = 0;
        while(cur < n && a[cur] != b[i]) {
            mx = max(mx, a[cur]);
            len++;
            cur++;
        }
        if(cur == n) return cout << -1 << endl, 0;
        cur++;
        ll res = INF;
        for(int j = 1; j * k <= len; j++) {
            res = min(res, 1LL * (len - j * k) * y + 1LL * x * j);
        }
        if(mx < b[i] || (i > 0 && mx < b[i - 1])) res = min(res, 1LL * len * y);
        if(res == INF) {
            return cout << -1 << endl, 0;
        }
        fres += res;
    }
    cout << fres << '\n';
}