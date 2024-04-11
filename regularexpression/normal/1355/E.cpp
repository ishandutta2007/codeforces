#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

#define ll long long
#define ld long double
#define int long long

int n, a, r, m, h[100000], pr[100001], su[100001];

int solve(int x) {
    int cl = lower_bound(h, h + n, x) - h;
    int sl = pr[cl];
    int cm = h + n - upper_bound(h, h + n, x);
    int sm = su[cm];
    sl = x * cl - sl;
    sm -= x * cm;
    int q = min(sl, sm);
    return q * m + (sl - q) * a + (sm - q) * r;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> r >> m;
    m = min(m, a + r);
    for (int i = 0; i < n; i++) cin >> h[i];
    sort(h, h + n);
    for (int i = 0; i < n; i++) {
        pr[i + 1] = pr[i] + h[i];
        su[i + 1] = su[i] + h[n - i - 1];
    }
    int ans = 2e18 + 7;
    for (int i = 0; i < n; i++) ans = min(ans, solve(h[i]));
    ans = min(ans, solve(pr[n] / n));
    ans = min(ans, solve((pr[n] + n - 1) / n));
    cout << ans;
    return 0;
}