#include<bits/stdc++.h>
using namespace std;

#define N 100010

int a[N];

int main() {
    int n, k, i;
    scanf("%d%d", &n, &k);
    k = n - k;
    for(i = 1; i <= n; i ++) a[i] = i;
    if(k == 0) {puts("-1"); return 0;}
    i = (k & 1) + 1;
    for( ; i < k; i += 2) a[i] ^= a[i + 1] ^= a[i] ^= a[i + 1];
    for(i = 1; i <= n; i ++) {
        if(i > 1) putchar(' ');
        printf("%d", a[i]);
    }
}