#include<stdio.h>

main() 
{
    int a[30],n,i,j,k,x,ans;
    char b[55];
    for(i=0;i<30;i++) a[i]=0;

    scanf("%d %d", &n, &k);
    scanf("%s", b);
    for(i=0;i<n;i++) a[b[i]-'a']=1;

    x=0;
    ans=0;

    for(i=0;i<30,x<k;i++) {
        if(a[i]==1) {
            x++;
            ans+=(i+1);
            i++;
        }
        if(i>28) break;
    }
    if(x<k) puts("-1");
    else printf("%d\n", ans);
}