#include <stdio.h>
#define N 100010

__int64 a[N], sum[N];

int main() {
    int n, i, lcnt, rcnt;
    __int64 l, r, L, R, ans, tmp;
    scanf("%d %I64d %I64d %I64d %I64d", &n, &l, &r, &L, &R);
    sum[0]=0;
    for (i=1; i<=n; i++) {
        scanf("%I64d", a+i);
        sum[i]=sum[i-1]+a[i];
    }
    ans=(1LL<<60);
    for (i=0; i<=n; i++) {
        lcnt=i, rcnt=n-i;
        tmp=sum[i]*l+(sum[n]-sum[i])*r;
        if (lcnt>rcnt) tmp+=L*(lcnt-rcnt-1);
        else if (lcnt<rcnt) tmp+=R*(rcnt-lcnt-1);
        if (tmp<ans) ans=tmp;
    }
    printf("%I64d\n", ans);
}