#include<bits/stdc++.h>
using namespace std;

#define N 60

int a[N], b[N];

int main() {
    int t;
    scanf("%d", &t);
    while(t --) {
        int n;
        scanf("%d", &n);
        int k, m;
        k = m = 2e9;
        for(int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
            k = min(a[i], k);
        }
        for(int i = 1; i <= n; i ++) {
            scanf("%d", &b[i]);
            m = min(b[i], m);
        }
        long long ans = 0;
        for(int i = 1; i <= n; i ++) {
            ans += max(a[i] - k, b[i] - m);
        }
        printf("%I64d\n", ans);
    }
}