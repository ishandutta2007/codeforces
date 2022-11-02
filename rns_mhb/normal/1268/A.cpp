#include<bits/stdc++.h>
using namespace std;

#define N 200010

char x[N], y[N];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", x);
    for(int i = 0; i < k; i ++) y[i] = x[i];
    for(int i = k; i < n; i ++) y[i] = y[i-k];
    int p = 0;
    while(p < n && x[p] == y[p]) p ++;
    if(p == n || y[p] > x[p]) {
        printf("%d\n", n);
        for(int i = 0; i < n; i ++) putchar(y[i]);
        putchar('\n');
        return 0;
    }
    p = k-1;
    while(y[p] == '9') p --;
    y[p] ++;
    for(int i = p+1; i < k; i ++) y[i] = '0';
    for(int i = k; i < n; i ++) y[i] = y[i-k];
    printf("%d\n", n);
    for(int i = 0; i < n; i ++) putchar(y[i]);
    putchar('\n');
}