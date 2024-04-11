#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
#define pb push_back
template<typename T> void domin(T &a, T b) { if (b < a) a = b; }
typedef long long ll;

const int MaxN = 5005;
const ll inf = 1e18;

int N;
ll X, s[MaxN], e[MaxN], dp[2][MaxN*2];
std::vector<ll> x;

int comp(ll a) {
    return std::lower_bound(x.begin(), x.end(), a) - x.begin();
}

int main()
{
    scanf("%d%lld", &N, &X);
    x.pb(X);
    for (int i = 0; i < N; i++) {
        scanf("%lld%lld", &s[i], &e[i]);
        x.pb(s[i]); x.pb(e[i]);
    }

    std::sort(x.begin(), x.end());
    x.erase(std::unique(x.begin(), x.end()), x.end());
    
    std::fill(dp[0], dp[0] + MaxN*2, inf);
    dp[0][comp(X)] = 0;
    int cur = 1, prev = 0;
    for (int i = 0; i < N; i++) {
        ll bestl = inf;
        for (int j = 0; j < sz(x); j++) {
            domin(bestl, dp[prev][j] - x[j]);
            dp[cur][j] = bestl + x[j];
        }
        ll bestr = inf;
        for (int j = sz(x)-1; j >= 0; j--) {
            domin(bestr, dp[prev][j] + x[j]);
            domin(dp[cur][j], bestr - x[j]);
        }
        for (int j = 0; j < sz(x); j++) {
            if (x[j] < s[i]) dp[cur][j] += s[i] - x[j];
            else if (e[i] < x[j]) dp[cur][j] += x[j] - e[i];
        }
        std::swap(cur, prev);
    }

    ll ans = inf;
    for (int j = 0; j < sz(x); j++) {
        domin(ans, dp[prev][j]);
    }
    printf("%lld\n", ans);
}