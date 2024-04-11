#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 2000
using namespace std;
int a[MAXN],b[MAXN],n;
int c[MAXN+1];
void out()
{
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        c[i]=-1;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&b[i]);
    int x=0,y=0,p=0,q=0;
    for(int i=0;i<n;i++)
    {
        if(c[a[i]]>=0)
        {
            x=c[a[i]];
            y=i;
            p=a[i];
        }
        else c[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
        if(c[i]<0)
        {
            q=i;
            break;
        }
    int t=a[x];
    a[x]=q;
    int cnt=0;
    for(int i=0;i<n;i++)
        if(a[i]!=b[i]) cnt++;
    if(cnt==1)
    {
        out();
        return 0;
    }
    a[x]=t;
    a[y]=q;
    out();
    return 0;
}