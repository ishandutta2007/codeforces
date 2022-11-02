#include<bits/stdc++.h>
using namespace std;

int a[1010][1010];

int main() {
    int n, i, j;
    scanf("%d", &n);
    for(i = 1; i < n; i ++) {
        for(j = 1; j < n; j ++) if(i != j) {
            a[i][j] = (i + j) % (n - 1);
            if(!a[i][j]) a[i][j] = n - 1;
        }
        a[i][0] = n * (n - 1) / 2;
        for(j = 1; j < n; j ++) a[i][0] -= a[i][j];
    }
    for(j = 0; j < n; j ++) {
        a[0][j] = n * (n - 1) / 2;
        for(i = 1; i < n; i ++) a[0][j] -= a[i][j];
    }
    for(i = 0; i < n; i ++) {
        for(j = 0; j < n; j ++) printf("%d ", a[i][j]);
        puts("");
    }
    return 0;
}