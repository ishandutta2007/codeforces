#include <bits/stdc++.h>
using namespace std;
 
#define N 2020
 
int n, d, a[N];
 
int main() {
    scanf("%d %d", &n, &d);
    int rlt = 0;
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
    for (int i = 1; i < n; i ++) {
        if (a[i] > a[i-1]) continue;
        int x = (a[i-1] - a[i]) / d + 1;
        rlt += x, a[i] += x * d;
    }
    printf("%d\n", rlt);
 
    return 0;
}