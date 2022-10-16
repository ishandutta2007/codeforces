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
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
int mmr[55],a[55],suf[55];
int dfs(int u,int h,int n)
{
	if(mmr[u])return mmr[u];
	if(u==n)return a[n];
	return mmr[u]=max(a[u]+suf[u+1]-dfs(u+1,h^1,n),dfs(u+1,h,n));
}
signed main()
{
	int n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=n;i>=1;i--)suf[i]=suf[i+1]+a[i];
	int x=dfs(1,1,n);
	printf("%lld %lld\n",suf[1]-x,x);
}