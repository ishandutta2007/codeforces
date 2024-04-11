#include<bits/stdc++.h>
using namespace std;

#define N 300010

int t, n, a[N], vis[N], pos[N];
bool b[N];

int main() {
    for(scanf("%d", &t); t --; ) {
        scanf("%d", &n);
        for(int i = 1; i <= n + 1; i ++) vis[i] = 0, b[i] = 0;
        for(int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
            if(a[i] <= n) vis[a[i]] ++, pos[a[i]] = i;
        }
        int k;
        for(k = 1; k <= n && vis[k] == 1; k ++);
        if(!vis[k]) k --;
        if(k == n) b[1] = 1;
        if(vis[1]) b[n] = 1;
        int l = 1, r = n;
        for(int i = 1; i < k; i ++) {
            if(pos[i] == l) {
                l ++;
                b[n - i] = 1;
                continue;
            }
            if(pos[i] == r) {
                r --;
                b[n - i] = 1;
                continue;
            }
            break;
        }
        for(int i = 1; i <= n; i ++) printf("%d", b[i]);
        puts("");
    }
}