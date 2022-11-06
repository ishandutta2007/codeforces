#include<string.h>
#include<stdio.h>
#include<math.h>

main()
{
    long long int a[14],x,y,k,t,tot,big=0;
    int i,j;
    for(i=0;i<14;i++) scanf("%I64d", &a[i]);

    for(i=0;i<14;i++) {
        x=a[i]/14;
        y=a[i]%14;
        k=i;
        tot=0;
        for(j=1;j<14;j++) {
            if(j+k>=14) k=k-14;
            t=a[j+k]+x;
            if(j<=y) t++;
            if(t%2==0) tot+=t;
        }
        if(x%2==0) tot+=x;

        if(tot>big) big=tot;
    }
    printf("%I64d\n", big);
}