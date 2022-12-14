#include <bits/stdc++.h>
using namespace std;

const int M = 3e6 + 1;

int vis[M];

void prepare() {
    for(int i = 2; i < M; i ++) vis[i] = 0;
    for(int i = 2; i < M; i ++) if(!vis[i]) {
        for(long long j = 1ll * i * i; j < M; j += i) vis[j] = 1;
    }

}

int b[M], res[M];

int main() {
    ///freopen("D.in", "r", stdin);
    prepare();
    int n;
    scanf("%d", &n);
    int cnt = 0;
    int m = 0;
    for(int i = 1; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        if(x == 1) cnt ++;
        else b[++m] = x;
    }
    int ans = cnt;
    for(int i = 0; i < ans; i ++) res[i] = 1;
    for(int i = 1; i <= m; i ++) {
        if(!vis[b[i] + 1]) {
            if(ans < cnt + 1) {
                ans = cnt + 1;
                for(int j = 0; j < ans; j ++) {
                    if(j < ans - 1) res[j] = 1;
                    else res[j] = b[i];
                }
            }
        }
    }
    for(int i = 1; i <= m; i ++) {
        for(int j = i + 1; j <= m; j ++) {
            if(!vis[b[i] + b[j]]) {
                if(ans < 2) {
                    ans = 2;
                    res[0] = b[i]; res[1] = b[j];
                }
            }
        }
    }
    if(ans < 1) {
        ans = 1;
        res[0] = b[1];
    }
    printf("%d\n", ans);
    for(int i = 0; i < ans; i ++) printf("%d ", res[i]); puts("");
}