#include<bits/stdc++.h>
using namespace std;

#define N 60

int a[N], b[N], w[N];
bool vis[110];

int main() {
    int t;
    scanf("%d", &t);
    while(t --) {
        int n;
        scanf("%d", &n);
        memset(a, 0, sizeof a);
        for(int i = 1; i <= n; i ++) {
            scanf("%d", &w[i]);
            a[w[i]] ++;
        }
        int ans = 0;
        memset(vis, 0, sizeof vis);
        for(int i = 1; i <= n; i ++) {
            for(int j = i; j <= n; j ++) {
                int s = w[i] + w[j];
                if(vis[s]) continue;
                vis[s] = 1;
                for(int m = 1; m <= n; m ++) b[m] = a[m];
                int r = 0;
                for(int m = 1; m <= n; m ++) {
                    if(w[m] * 2 == s) {
                        if(b[w[m]] < 2) continue;
                        else b[w[m]] -= 2, r ++;
                        continue;
                    }
                    if(w[m] < s && s - w[m] <= n && b[w[m]] && b[s - w[m]]) b[w[m]] --, b[s - w[m]] --, r ++;
                }
                ans = max(r, ans);
            }
        }
        printf("%d\n", ans);
    }
}