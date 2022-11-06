#include<stdio.h>

main()
{
    long long int n,d,b,a,i,ans=0;
    scanf("%I64d %I64d", &n, &d);
    scanf("%I64d", &b);
    for(i=1;i<n;i++) {
        scanf("%I64d", &a);
        if(a-b==2*d) ans++;
        if(a-b>2*d) ans+=2;
        b=a;
    }
    printf("%I64d\n", ans+2);
}