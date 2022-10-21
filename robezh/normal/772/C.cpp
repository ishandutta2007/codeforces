#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50, INF = (int)1e9 + 50;

int n, m;
bool bad[N];
int id[N];
vector<int> G[N], vals[N];
int dp[N], pre[N];
int psum[N];
int cnt = 0;

ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll d = a;
    if(b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else {
        x = 1; y = 0;
    }
    return d;
}

int get_sol(int a, int b, int mod) {
//    int g = __gcd(a, b);
//    a /= g, b /= g;

    ll x, y;
    extgcd(a, mod, x, y);
    x *= b / __gcd(a, mod);
    x = (x % mod + mod) % mod;
    return (int)x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        if(a == 0) a += m;
        bad[a] = true;
    }
//    for(int i = 1; i <= n; i++) if(n % i == 0) id[i] = cnt++;
    for(int i = 1; i <= m; i++) {
        if(bad[i]) continue;
        int g = __gcd(i, m);
        vals[g].push_back(i);
    }
//    fill(dp, dp + N, INF);
    fill(pre, pre + N, -1);
    for(int i = 1; i <= m; i++) {
        dp[i] += vals[i].size();
        for(int j = 2 * i; j <= m; j += i) {
            int cur = dp[i];
            if(cur > dp[j]) {
                dp[j] = cur;
                pre[j] = i;
            }
        }
    }
    int mx = 0, cur = -1;
    for(int i = 1; i <= m; i++) {
        if(dp[i] > mx) mx = dp[i], cur = i;
    }
    vector<int> psum;
    while(cur != -1) {
        for(int x : vals[cur]) psum.push_back(x);
        cur = pre[cur];
    }
    reverse(psum.begin(), psum.end());
    if(psum.empty()) return cout << 0 << endl, 0;

    vector<int> res(psum.size(), 0);
    res[0] = psum[0] % m;
    for(int i = 1; i < psum.size(); i++) {
        res[i] = get_sol(psum[i-1], psum[i], m);
    }

//    for(int x : psum) cout << x << " ";
//    cout << endl;
    cout << res.size() << endl;
    for(int x : res) cout << x << " ";


}