// Problem: B. Yet Another Crosses Problem
// Contest: Codeforces - Educational Codeforces Round 68 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1194/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
//#define int long long
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
	while(c!='.'&&c!='*')c=getchar();
	return c=='*';
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
int **a;
int c[1000005],r[1000005];
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read(),m=read();
		a=new int*[n];
		for(int i=0;i<n;i++)a[i]=new int[m];
		for(int i=0;i<n;i++)//scanf("%s",a[i]);
			for(int j=0;j<m;j++)a[i][j]=re1d();
		int maxn=0,maxm=0;
		memset(c,0,sizeof(int)*(m+3));
		memset(r,0,sizeof(int)*(n+3));
		int minn=0;
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)r[i]+=a[i][j],c[j]+=a[i][j];
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)//r[i]+=a[i][j],c[j]+=a[i][j];
			minn=max(minn,r[i]+c[j]-a[i][j]);
		//for(int i=0;i<n;i++)maxn=max(maxn,r[i]);
	//	for(int i=0;i<m;i++)maxm=max(maxm,c[i]);
		printf("%d\n",n+m-1-minn);
		
		delete[] a;
	}
}