#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
const int N = (int)5e5 + 50;
const ll INF = (ll)1e18;

int n, m, a[N], b[N], p[N];
int nxt[N], pv[N];
ll mx[N], dp[N];

ll bit[N];
ll sum = 0;

void add(int x, int val) {
    for(int i = x; i < N; i |= i + 1) bit[i] += val;
}

ll get(int x) {
    ll res = 0;
    for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i], a[i]--;
    for(int i = 0; i < n; i++) cin >> p[i], sum += p[i];
    cin >> m;
    for(int i = 0; i < m; i++) cin >> b[i], b[i]--;
    fill(nxt, nxt + n, -1);
    fill(pv, pv + n, -1);
    for(int i = 0; i < m; i++) {
        nxt[b[i]] = (i + 1 == m ? n : b[i + 1]);
        pv[b[i]] = (i == 0 ? -1 : b[i - 1]);
    }
    fill(mx, mx + N, -INF);
//    for(int i = 0; i < n; i++) cout << nxt[i] << " ";
//    cout << '\n';
//    fill(la, la + N, -1);
    mx[n] = 0;
    for(int i = n - 1; i >= 0; i--) {
        dp[i] = -INF;
//        if(nxt[a[i]] == -1) continue;
        if(nxt[a[i]] != -1 && mx[nxt[a[i]]] != -INF) dp[i] = p[i] + get(a[i]) + mx[nxt[a[i]]];
        if(p[i] > 0) add(a[i], p[i]);
        if(dp[i] != -INF) mx[a[i]] = max(mx[a[i]], dp[i] - get(pv[a[i]]));
    }
    ll res = -INF;
    for(int i = 0; i < n; i++) {
        if(a[i] == b[0]) res = max(res, dp[i]);
    }
    if(res == -INF) cout << "NO\n";
    else cout << "YES\n" << sum - res << '\n';

}