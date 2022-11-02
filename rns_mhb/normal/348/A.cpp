#include <stdio.h>
#define max(a, b) ((a)>(b)?(a):(b))
#define N 100100

__int64 a[N];

int main() {
    int n, i;
    __int64 s=0, mx=0;
//  freopen ("in.txt", "r", stdin);
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%I64d", a+i);
        mx=max(a[i], mx);
        s+=a[i];
    }
    printf("%I64d\n", max(mx, (s+n-2)/(n-1)));
}