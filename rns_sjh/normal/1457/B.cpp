#include<bits/stdc++.h>
using namespace std;

#define N 100010

int t, n, k, c[N];

int main() {
    for(scanf("%d", &t); t --; ) {
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i ++) {
            scanf("%d", &c[i]);
        }
        int a = 1e6;
        for(int i = 1; i <= 100; i ++) {
            int b = 0;
            for(int j = 1; j <= n; ) {
                if(c[j] == i) {
                    j ++;
                    continue;
                }
                b ++;
                j += k;
            }
            a = min(a, b);
        }
        printf("%d\n", a);
    }
}