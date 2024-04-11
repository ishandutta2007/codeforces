#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <unordered_map>
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
const  int mod=1000000007;
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
int f[1005][1005][2];
int dfs(int i,int k,int d,int n)
{
    if(k==1)return 1;
    if(f[i][k][d])return f[i][k][d];
    int ans=2;
    if(d)
    {
        if(i<n)ans+=dfs(i+1,k,d,n)-1;
        if(i>1)ans+=dfs(i-1,k-1,d^1,n)-1;
        return f[i][k][d]=ans%mod;
    }
    else
    {
        if(i>1)ans+=dfs(i-1,k,d,n)-1;
        if(i<n)ans+=dfs(i+1,k-1,d^1,n)-1;
        return f[i][k][d]=ans%mod;
    }
    return 114514;
}
signed main()
{
    //srand(19260817);
    //int n=rand()%8+3;
    int T=read();
    while(T--)
    {
        int n=read(),k=read();
        memset(f,0,sizeof(f));
        printf("%lld\n",dfs(1,k,1,n));
    }
}