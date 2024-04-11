#include<bits/stdc++.h>
using namespace std;

int r[105];

int main() {
    int n, k, i, a, ans = -1;
    scanf("%d%d", &n, &k);
    for(i = 1; i <= n; i ++) scanf("%d", &a), r[a] ++;
    bool fl = 1;
    while(fl) {
        fl = 0;
        for(i = k - 1; i; i --) if(r[i]) {
            fl = 1;
            r[i] --;
            r[i + 1] ++;
        }
        ans ++;
    }
    printf("%d\n", ans);
}