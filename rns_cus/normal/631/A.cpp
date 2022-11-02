#include <bits/stdc++.h>

using namespace std;

#define N 1010

int a[N], b[N], A[N], B[N];

int main() {
    int n, m;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", a + i);
    for(int i = 1; i <= n; i ++) scanf("%d", b + i);
    int ans = 0, aa, bb;
    for(int i = 1; i <= n; i ++) {
        aa = bb = 0;
        for(int j = i; j; j --) {
            aa |= a[j]; bb|= b[j];
            int tp = aa + bb;
            if(ans < tp) ans = tp;
        }
    }
    printf("%d\n", ans);
    return 0;
}