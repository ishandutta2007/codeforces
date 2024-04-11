#include<stdio.h>
#include<math.h>

main()
{
    long long int n,q,warr[200005],x,y=0,i,k,h,l;
    scanf("%I64d %I64d", &n, &q);
    for(i=1;i<=n;i++) {
        scanf("%I64d", &x);
        y=y+x;
        warr[i]=y;
    }
    x=0;
    y=0;

    for(i=1;i<=q;i++) {
        scanf("%I64d", &k);
        x=x+k;

        if(x>=warr[n]) {
            y=0;
            x=0;
            goto end;
        }
        if(x<warr[1]) {
            y=0;
            goto end;
        }

        h=n;
        l=0;
        for(;;) {
            y=(h+l)/2;
            if(warr[y]<=x && x<warr[y+1]) break;
            if(warr[y]>x) h=y;
            if(x>=warr[y+1]) l=y;
        }

        end: ;

        printf("%I64d\n", n-y);
    }
}