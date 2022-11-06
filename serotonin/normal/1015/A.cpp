#include<stdio.h>
#include<math.h>
#include<string.h>

main()
{
    int x,y,z,i,j,k,f,ans,n,m;
    scanf("%d %d", &n, &m);
    int a[105],q[105];
    for(i=0;i<=m;i++) a[i]=0;

    for(i=0;i<n;i++) {
        scanf("%d %d", &x, &y);
        for(j=x;j<=y;j++) a[j]++;
    }
    ans=0;
    for(i=1;i<=m;i++) {
        if(a[i]==0) {
            q[ans]=i;
            ans++;
        }
    }
    printf("%d\n", ans);
    for(i=0;i<ans;i++) {
        if(i==ans-1) printf("%d\n", q[i]);
        else printf("%d ", q[i]);
    }
}