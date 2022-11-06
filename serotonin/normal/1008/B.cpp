#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

main()
{
    long long int n,a,b,f=0,x,i,j;
    scanf("%I64d", &n);
    scanf("%I64d %I64d", &a, &b);
    if(a>=b) x=a;
    else x=b;
    for(i=1;i<n;i++) {
        scanf("%I64d %I64d", &a, &b);
        if(x>=a && x>=b) {
            if(a>=b) x=a;
            else x=b;
        }
        else if(x>=a) x=a;
        else if(x>=b) x=b;
        else f=1;
    }
    if(f==1) printf("NO\n");
    else printf("YES\n");
}