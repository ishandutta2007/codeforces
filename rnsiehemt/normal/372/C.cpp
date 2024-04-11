#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 150*1000+5;

int n, m, d;
ll dp[maxn];
std::vector<std::pair<ll,int>> q; int start;

int main() {
    scanf("%d%d%d", &n, &m, &d);
    int lastt = 0;
    for (int i = 0; i < m; i++) {
        int a, b, t; scanf("%d%d%d", &a, &b, &t); a--;
        if (t != lastt) {
            int k = std::min(ll(d)*(t-lastt), ll(n));
            q.clear(); start = 0;
            for (int i = 0; i < n && i < k; i++) {
                while (start < int(q.size()) && q.back().first < dp[i]) q.pop_back();
                q.emplace_back(dp[i], i);
            }
            for (int i = 0; i < n; i++) {
                if (i+k < n) {
                    while (start < int(q.size()) && q.back().first < dp[i+k]) q.pop_back();
                    q.emplace_back(dp[i+k], i+k);
                }
                while (start < int(q.size()) && q[start].second < i-k) start++;
                dp[i] = q[start].first;
            }
            lastt = t;
        }
        for (int j = 0; j < n; j++) dp[j] += b - std::abs(a-j);
    }
    ll ans = -2e18;
    for (int i = 0; i < n; i++) if (dp[i] > ans) ans = dp[i];
    printf("%lld\n", ans);
}