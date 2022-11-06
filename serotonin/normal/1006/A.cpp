#include<math.h>
#include<stdio.h>

main()
{
    int n,i,x,j,a[1005];
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        scanf("%d", &x);
        if(x%2==0) x--;
        a[i]=x;
    }
    for(i=0;i<n;i++) {
        if(i<n-1) printf("%d ", a[i]);
        else printf("%d\n", a[i]);
    }
}