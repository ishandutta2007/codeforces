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
const int N = (int)1e5 + 50;
const ll INF = (ll)1e18 + 50;

int n;
struct P {
    int a, c;
} p[N];
int a[N];
ll dp[N];
ll mn[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    ll sum = 0;
    rep(i, 0, n) {
        cin >> p[i].a >> p[i].c;
        sum += p[i].c;
    }
    sort(p, p + n, [](const P &p1, const P &p2) {
        return p1.a < p2.a;
    });
    rep(i, 0, n) a[i] = p[i].a;
    fill(dp, dp + n, INF);
    fill(mn, mn + n, INF);
    int r = 0;
    rep(i, 0, n) {
        if(i > r) {
            dp[i] = mn[i];
        } else {
            dp[i] = (i == 0 ? 0 : dp[i - 1]);
        }
        int nxt = upper_bound(a, a + n, a[i] + p[i].c) - a;
        r = max(r, nxt - 1);
        if(nxt < n) mn[nxt] = min(mn[nxt], dp[i] + (a[nxt] - a[i]) - p[i].c);
    }
    cout << sum + dp[n - 1] << '\n';

}