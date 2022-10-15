#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k;
int a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n+1;i++)
        scanf("%d",&a[i]);
    bool f=true;
    int t=0;
    for(int i=1;i<n+1;i++)
        if((a[i-1]>=2&&a[i]>=2)) {t=i; f=false; break;}
    if(f)
    {
        puts("perfect");
        return 0;
    }
    puts("ambiguous");
    int s=0;
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<a[i];j++)
            printf("%d ",s);
        s+=a[i];
    }
    s=0;
    printf("\n");
    for(int i=0;i<t;i++)
    {
        for(int j=0;j<a[i];j++)
            printf("%d ",s);
        s+=a[i];
    }
    printf("%d ",s-1);
    for(int j=0;j<a[t]-1;j++)
        printf("%d ",s);
    s+=a[t];
    for(int i=t+1;i<n+1;i++)
    {
        for(int j=0;j<a[i];j++)
            printf("%d ",s);
        s+=a[i];
    }
    return 0;
}