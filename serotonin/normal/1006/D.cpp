#include<stdio.h>
char a[100005],b[100005];
main()
{
    int i,n,k,ans=0;
    scanf("%d", &n);
    scanf("%s %s", a, b);
    for(i=0;i<n/2;i++) {
        k=0;
        if(a[i]!=a[n-1-i]) {
            if(a[i]==b[i] || a[i]==b[n-1-i]) k++;
            if(a[n-1-i]==b[i] || a[n-1-i]==b[n-1-i]) k++;
            if(k==0 && b[i]==b[n-1-i]) k++;
        }
        else {
            if(a[i]==b[i]) k++;
            if(a[i]==b[n-1-i]) k++;
            if(b[i]==b[n-1-i]) k=2;
        }
        ans+=2-k;
    }
    if(n%2==1) if(b[n/2]!=a[n/2]) ans++;
    printf("%d\n", ans);
}