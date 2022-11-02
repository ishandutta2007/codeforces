#include <bits/stdc++.h>

using namespace std;

#define N 100100

int n, m, k;
int a[N], b[N], c[N];

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= k; i ++) {
        int t, x, y;
        scanf("%d %d %d", &t, &x, &c[i]);
        if(t == 1) {
            a[x] = i;
        } else b[x] = i;
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            int k = max(a[i], b[j]);
            if(j > 1) printf(" ");
            printf("%d", c[k]);
        }
        puts("");
    }
    return 0;
}