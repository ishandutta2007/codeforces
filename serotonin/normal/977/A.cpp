#include<stdio.h>
#include<math.h>
main()
{
    long long int i,n,k;
    scanf("%I64d %I64d", &n, &k);

    for(i=0;i<k;i++) {
        if(n%10==0) n/=10;
        else n--;

        if(n==1) break;
    }
    printf("%I64d\n", n);
}