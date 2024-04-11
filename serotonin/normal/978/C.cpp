#include<stdio.h>
#include<math.h>
#include<string.h>
long long int a[200005];
int main()
{
    a[0]=0;
    long long int b,h,l,x,n,m,i,j,k;
    scanf("%I64d %I64d", &n, &m);
    for(i=1;i<=n;i++) {
        scanf("%I64d", &x);
        a[i]=a[i-1]+x;
    }
    for(i=0;i<m;i++) {
        scanf("%I64d", &b);
        h=n;
        l=1;
        for(;;) {
            x=(h+l)/2;
            if(b>a[x-1] && b<=a[x]) break;
            if(b<=a[x-1] && b<a[x]) h=x-1;
            if(b>a[x-1] && b>a[x]) l=x+1;
        }
        printf("%I64d ", x);
        printf("%I64d\n", b-a[x-1]);
    }
}