#include<stdio.h>
#include<math.h>

long long int d[200005],a[200005],c[200005];

main()
{
    long long int x=0,i,j,k,y,l,n,z=0,f=0;
    scanf("%I64d", &n);
    for(i=0;i<n;i++) {
        scanf("%I64d", &d[i]);
        x+=d[i];
        a[i]=x;
    }
    l=a[n-1];
    x=0;
    for(i=n-1;i>=0;i--) {
        x+=d[i];
        c[i]=x;
        if(i<n-1) {
            y=a[i]-c[i+1];
            if(y<0) y=0-y;

            if(y<l) {
                l=y;
                z=i;
            }
        }
    }

    x=z;
    y=z+1;
    for(;;) {
        if(x<0 || y>n-1) {
            f++;
            break;
        }

        if(a[x]==c[y]) break;
        else if(a[x]>c[y]) x--;
        else if(a[x]<c[y]) y++;
    }

    if(f==0) printf("%I64d\n", a[x]);
    else printf("0\n");
}