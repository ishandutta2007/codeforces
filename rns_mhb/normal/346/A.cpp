#include <stdio.h>
#define max(a, b) ((a)>(b)?(a):(b))
#define N 110

int a[N];

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a%b);
}

int main() {
    int n, i, mx=0, t, r;
//  freopen ("in.txt", "r", stdin);
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", a+i);
        mx=max(mx, a[i]);
    }
    t=gcd(a[0], a[1]);
    for (i=2; i<n; i++) t=gcd(t, a[i]);
    r=mx/t-n;
    if (r&1) puts("Alice");
    else puts("Bob");
}