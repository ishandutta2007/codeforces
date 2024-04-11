#include <bits/stdc++.h>
using namespace std;

#define N 1005

int n, k;
int a[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    a[0] = 1;
    for (int i = 1; i <= n; i ++) {
        if (__gcd(a[i], a[i-1]) > 1) k ++;
    }
    printf("%d\n", k);
    for (int i = 1; i <= n; i ++) {
        if (__gcd(a[i], a[i-1]) > 1) printf("1 ");
        printf("%d ", a[i]);
    }
    return 0;
}