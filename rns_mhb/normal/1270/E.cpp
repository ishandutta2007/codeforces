#include<bits/stdc++.h>
using namespace std;

#define N 1010

int x[N], y[N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d%d", &x[i], &y[i]);
    while(1) {
        int a = 0, b = 0;
        for(int i = 1; i <= n; i ++) {
            if(x[i] + y[i] & 1) a ++;
            else b ++;
        }
        if(a && b) {
            printf("%d\n", a);
            for(int i = 1; i <= n; i ++) if(x[i] + y[i] & 1) printf("%d ", i);
            puts("");
            return 0;
        }
        if(a) {
            for(int i = 1; i <= n; i ++) {
                int xx = x[i], yy = y[i];
                x[i] = (xx + yy + 1) / 2;
                y[i] = (xx - yy + 1) / 2;
            }
        }
        if(b) {
            for(int i = 1; i <= n; i ++) {
                int xx = x[i], yy = y[i];
                x[i] = (xx + yy) / 2;
                y[i] = (xx - yy) / 2;
            }
        }
    }
}