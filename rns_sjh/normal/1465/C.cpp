#include<bits/stdc++.h>
using namespace std;

#define N 100010

int t, n, m, a[N], b[N];
bool vis[N];

int main() {
    for(scanf("%d", &t); t --; ) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i ++) vis[i] = 0, a[i] = 0, b[i] = 0;
        while(m --) {
            int x, y;
            scanf("%d%d", &x, &y);
            a[x] = y;
            b[y] = x;
        }
        int ans = 0;
        for(int i = 1; i <= n; i ++) if(!vis[i] && a[i]) {
            if(a[i] == i) {
                vis[i] = 1;
                continue;
            }
            vis[i] = 1;
            int cnt = 1;
            int r = a[i];
            while(!vis[r] && a[r]) vis[r] = 1, r = a[r], cnt ++;
            if(!a[r]) ans += cnt;
            else if(r == i) ans += cnt + 1;
            else ans += cnt;
        }
        printf("%d\n", ans);
    }
}