#include<bits/stdc++.h>
#define MAXN 5005
using namespace std;
int n,k;
char str[MAXN];
int a[MAXN];
int main()
{
    scanf("%s",str);
    int n=strlen(str);
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++)
        if(str[i]=='a') a[i+1]=a[i]+1; else a[i+1]=a[i];
    int ans=0;
    for(int i=0;i<n;i++)
        for(int j=i;j<=n;j++)
            ans=max(ans,a[i]+a[n]-a[j]+j-i-a[j]+a[i]);
    printf("%d\n",ans);
    return 0;
}