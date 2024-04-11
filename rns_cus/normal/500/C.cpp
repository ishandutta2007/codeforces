#include <bits/stdc++.h>
using namespace std;

#define M 2001

int a[M], b[M], c[M], vis[M];
int n, m;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    int cnt = 0;
    for(int i = 1; i <= m; i ++) {
        scanf("%d", &b[i]);
        if(!vis[b[i]]) c[++cnt] = b[i];
        vis[b[i]] = 1;
    }
    int ans = 0;
    for(int i = 1; i <= m; i ++) {
        int j;
        for(j = 1; j <= cnt; j ++) {
            if(c[j] == b[i]) break;
            ans += a[c[j]];
        }
        for(int k = j; k >= 2; k --) c[k] = c[k-1];
        c[1] = b[i];
    }
    cout << ans << endl;
}