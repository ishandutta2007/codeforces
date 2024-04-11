#include <bits/stdc++.h>
using namespace std;

#define N 300300

int n, a[N], nxt[N], dp[N];

unordered_map <int, int> mp[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), mp[i].clear();
        a[n + 1] = 0; mp[n+1].clear();
        for (int i = n; i; i --) {
            nxt[i] = 0;
            if (a[i + 1] == a[i]) {
                nxt[i] = i + 2;
                swap(mp[i], mp[i+2]);
                mp[i][a[i+2]] = i + 2;
            }
            else {
                int k = mp[i+1][a[i]];
                if (!k) continue;
                nxt[i] = k + 1;
                swap(mp[i], mp[k+1]);
                mp[i][a[k+1]] = k + 1;
            }
        }
        dp[n+1] = 0;
        long long ans = 0;
        for (int i = n; i; i --) {
            dp[i] = dp[nxt[i]];
            if (nxt[i]) dp[i] ++;
            ans += dp[i];
        }
        printf("%I64d\n", ans);
    }
}