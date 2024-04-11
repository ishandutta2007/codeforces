#include <bits/stdc++.h>
using namespace std;

#define N 1000100

int sum[N], le[N], dp[N];
char s[N];
map <int, int> mp;

int mx = 0, cnt = 1;

inline void update(int x) {
    if (x > mx) mx = x, cnt = 1;
    else if (x == mx) cnt ++;
}

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    mp[0] = 0;
    le[0] = -1;
    for (int i = 1; i <= n; i ++) {
        sum[i] = sum[i-1];
        if (s[i] == '(') sum[i] ++;
        else sum[i] --;

        int u = i - 1;
        while (u >= 0 && sum[u] >= sum[i]) u = le[u];
        le[i] = u;

        int x = sum[i];
        if (mp.find(x) == mp.end()) {
            mp[x] = i; continue;
        }
        int &k = mp[x];
        if (k >= le[i]) update(dp[i] = dp[k] + i - k);
        k = i;
    }
    printf("%d %d\n", mx, cnt);

    return 0;
}