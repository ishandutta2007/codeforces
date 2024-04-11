#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int vis[maxn], pri[maxn], g[maxn], cnt[maxn], re[maxn], top = 0, n, t = 0;
int pwl[maxn], z = 0;
int main(){
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        if (!vis[i]){
            vis[i] = 1; pri[++t] = i; g[i] = t;
        }
        for (int j = 1; j <= t && i * pri[j] <= n; j++){
            vis[i * pri[j]] = 1;
            g[i * pri[j]] = j;
            if (i % pri[j] == 0) break;
        }
    }
    for (int i = 2; i <= n; i++) cnt[g[i]]++;
    int c;
    int blk = 100, now = n, flag = 0, last = 1;
    for (int i = 1; i <= t; i++){
        if (i % blk == 1 && i != 1 && !flag){
            printf("A %d\n", 1);
            fflush(stdout);
            scanf("%d", &c);
            if (now != c) {
                flag = 1;
                for (int j = last ; j < i; j++){
                    printf("A %d\n", pri[j]);
                    fflush(stdout);
                    scanf("%d", &c);
                    if (c != 0){
                        re[++top] = j;
                        break;
                    }
                }
            }
            last = i;
        }
        printf("B %d\n", pri[i]);
        fflush(stdout);
        scanf("%d", &c);
        if (c != cnt[i]) re[++top] = i;
        now -= cnt[i];
    }
    if (!flag){
        for (int j = last ; j <= t; j++){
            printf("A %d\n", pri[j]);
            fflush(stdout);
            scanf("%d", &c);
            if (c != 0){
                re[++top] = j;
                break;
            }
        }
    }
    int ans = 1;
    for (int i = 1; i <= top; i++) {
        long long pw = pri[re[i]];
        z = 0;
        int as = 1;
        while (pw <= n) pwl[++z] = pw, pw *= pw;
        for (int j = z; j >= 1; j--){
            if (1LL * as *pwl[j] <= n){
                printf("A %d\n", as * pwl[j]);
                fflush(stdout);
                scanf("%d", &c);
                if (c != 0) as *= pwl[j];
            }
        }
        ans *= as;
    }
    printf("C %d\n", ans);
    fflush(stdout);
    return 0;
}