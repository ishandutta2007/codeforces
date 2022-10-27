#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<string.h>
#include<vector>
using namespace std;
typedef __int64 ll;
const int inf=1000000000;
int a[200000+10];
int b[200000+10];
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        char c;cin>>c;
        if(c=='R') b[i]=1;
        else b[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int l,r;l=r=0;
    int res=inf;
    for(int i=1;i<=n;i++)
    {
        if(b[i]==1) r=max(r,i);
        else l=max(l,i);

        if((r<l)&&(r!=0)) res=min(res,(a[l]-a[r])/2);
    }
    if(res==inf) cout<<-1;
    else cout<<res;
    return 0;
}