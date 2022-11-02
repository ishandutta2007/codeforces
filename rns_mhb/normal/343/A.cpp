#include <stdio.h>

int main() {
    __int64 a, b, t, r=0;
//  freopen ("in.txt", "r", stdin);
    scanf("%I64d %I64d", &a, &b);
    if (a>b) t=a, a=b, b=t;
    while (a) {
        r+=b/a;
        t=b%a;
        b=a, a=t;
    }
    printf("%I64d\n", r);
}