#include<bits/stdc++.h>
using namespace std;

#define N 100010

int a[N], sum[N], m[N];

int main() {
    int t;
    scanf("%d", &t);
    while(t --) {
        int n, k, z;
        scanf("%d%d%d", &n, &k, &z);
        sum[0] = 0;
        for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
        m[1] = a[1] + a[2];
        for(int i = 2; i < n; i ++) {
            m[i] = max(m[i - 1], a[i] + a[i + 1]);
        }
        int ans = 0;
        for(int y = 0; y <= z; y ++) {
            if(y * 2 > k) continue;
            int r = sum[k + 1 - 2 * y];
            r += y * m[k + 2 - 2 * y];
            ans = max(r, ans);
        }
        printf("%d\n", ans);
    }
}