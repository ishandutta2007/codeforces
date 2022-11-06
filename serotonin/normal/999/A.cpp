#include<stdio.h>
#include<math.h>


main()
{
    int n,k,i,p[101],f=0,ans=0;
    scanf("%d %d", &n, &k);
    for(i=0;i<n;i++) {
        scanf("%d", &p[i]);
        if(p[i]>k) f++;
        if(f==0) ans++;
    }
    for(i=n-1;i>=0;i--) {
        if(p[i]>k) break;
        ans++;
    }
    if(f==0) ans=ans/2;
    printf("%d\n", ans);
}