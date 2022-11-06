#include<stdio.h>
#include<math.h>

main()
{
    long long int n,m,k,x,y;
    scanf("%lld %lld %lld", &n, &m ,&k);
    if(k<n) printf("%lld 1\n", k+1);
    else {
        k=k-n;
        x=k/(m-1);

        y=k%(m-1);

        if(x%2==0) y=y+2;
        else y=m-y;

        x=n-x;

        printf("%lld %lld\n", x, y);
    }
}