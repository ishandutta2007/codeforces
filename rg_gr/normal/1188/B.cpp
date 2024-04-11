#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <bitset>
#include <map>
#include <algorithm>
#define int long long
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
int a[100005*2];
std::map<int,int> mp;
signed main()
{
    int n=read(),mod=read(),k=read();
    for(int i=0;i<n;i++)
    {
        int x=read();
        int qwq=x*x%mod;
        qwq=qwq*qwq%mod;
        qwq-=k*x;
        qwq%=mod;
        qwq+=mod;
        qwq%=mod;
        mp[qwq]++;
    }
    int ans=0;
    for(std::map<int,int>::iterator it=mp.begin(),en=mp.end();it!=en;it++)
    {
        int x=it->second;
        ans+=(x-1)*x/2;
    }
    printf("%lld\n",ans);
    return 0;
}