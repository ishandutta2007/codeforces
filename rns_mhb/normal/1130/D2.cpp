#include<bits/stdc++.h>
using namespace std;

#define N 5010

int n, m;

int dist(int i, int j) {
    if(i <= j) return j - i;
    else return j + n - i;
}

int cnt[N], mn[N];

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < N; i ++) mn[i] = 1e9;
    for(int i = 1, x, y; i <= m; i ++) {
        scanf("%d%d", &x, &y);
        mn[x] = min(mn[x], dist(x, y));
        cnt[x] ++;
    }
    for(int i = 1; i <= n; i ++) if(cnt[i]) cnt[i] = n * (cnt[i] - 1) + mn[i];
    for(int i = 1; i <= n; i ++) {
        int ans = 0;
        for(int j = 1; j <= n; j ++) if(cnt[j]) ans = max(ans, cnt[j] + dist(i, j));
        printf("%d ", ans);
    }
    puts("");
}