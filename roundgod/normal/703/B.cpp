#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAXN 100000
using namespace std;
typedef long long ll;
int val[MAXN];
bool capi[MAXN];
int n,k;
int main()
{
    scanf("%d%d",&n,&k);
    ll s=0,ans=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&val[i]);
        s+=val[i];
        if(i>0) ans+=val[i]*val[i-1];
    }
    ans+=val[n-1]*val[0];
    int x;
    memset(capi,false,sizeof(capi));
    for(int i=0;i<k;i++)
    {
        scanf("%d",&x);
        x--;
        s-=val[x];
        capi[x]=true;
        if(x==0)
        {
            if(capi[1]&&capi[n-1])
                ans+=val[x]*s;
            else if(capi[1])
                ans+=val[x]*(s-val[n-1]);
            else if(capi[n-1])
                ans+=val[x]*(s-val[1]);
            else ans+=val[x]*(s-val[1]-val[n-1]);
        }
        else if(x==n-1)
        {
            if(capi[0]&&capi[n-2])
                ans+=val[x]*s;
            else if(capi[0])
                ans+=val[x]*(s-val[n-2]);
            else if(capi[n-2])
                ans+=val[x]*(s-val[0]);
            else ans+=val[x]*(s-val[0]-val[n-2]);
        }
        else
        {
             if(capi[x-1]&&capi[x+1])
                ans+=val[x]*s;
            else if(capi[x-1])
                ans+=val[x]*(s-val[x+1]);
            else if(capi[x+1])
                ans+=val[x]*(s-val[x-1]);
            else ans+=val[x]*(s-val[x-1]-val[x+1]);
        }
    }
    printf("%I64d",ans);
    return 0;
}