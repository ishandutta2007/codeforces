// Problem: B. Word Cut
// Contest: Codeforces - Croc Champ 2012 - Round 2
// URL: https://codeforces.com/contest/176/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
inline int re1d()
{
	char c=getchar();
	while(c<48||c>49)c=getchar();
	return c&1;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
char a[500005],b[500005];
int dp[500005][2];
int cmp(int l,int r)
{
	for(int i=l,j=0;i<r;i++,j++)if(a[i]!=b[j])return 0;
	return 1;
}
const int mod=1000000007;
signed main()
{
	scanf("%s%s",a,b);
	int n=strlen(a),k=0,t=read();
	for(int i=0;i<n;i++)a[i+n]=a[i];
	for(int i=0;i<n;i++)k+=cmp(i,i+n);
	dp[0][cmp(0,n)^1]=1;
	for(int i=1;i<=t;i++)
	{
		dp[i][0]=(dp[i-1][1]*k+dp[i-1][0]*(k-1))%mod;
		dp[i][1]=(dp[i-1][0]*(n-k)+dp[i-1][1]*(n-k-1))%mod;
	}
	printf("%lld\n",dp[t][0]);
}