// Problem: B. Resource Distribution
// Contest: Codeforces - Codeforces Round #477 (rated, Div. 1, based on VK Cup 2018 Round 3)
// URL: https://codeforces.com/contest/966/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
#define od(x) printf("%d",x)
#define odb(x) printf("%d ",x)
#define odl(x) printf("%d\n",x)
#define odp(x,y) printf("%d %d\n",x,y)
#define ol(x) puts("")
#define old(x) printf("%lld",x)
#define oldb(x) printf("%lld ",x)
#define oldl(x) printf("%lld\n",x)
#define oldp(x,y) printf("%lld %lld\n",x,y)
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
struct Node{
	int a,pos;
	bool operator<(const Node&b)const{return a>b.a;}
}a[300005];
signed main()
{
	int n=read(),l=read(),r=read();
	for(int i=1;i<=n;i++)a[i]=(Node){read(),i};
	std::sort(a+1,a+1+n);
	{
		int sum=0,pos=0;
		for(int i=1;i<=n;i++)
		{
			sum=a[i].a;
			if(sum*i>=l)
			{
				pos=i;
				break;
			}
		}
		if(pos==0)goto fail1;
		sum=0;
		for(int i=pos+1;i<=n;i++)
		{
			sum=a[i].a;
			if(sum*(i-pos)>=r)
			{
				puts("Yes");
				oldp(pos,i-pos);
				for(int j=1;j<=pos;j++)oldb(a[j].pos);puts("");
				for(int j=pos+1;j<=i;j++)oldb(a[j].pos);puts("");
				return 0;
			}
		}
		goto fail1;
	}
	fail1:;
	{
//		puts("?");
		l^=r^=l^=r;
		int sum=0,pos=0;
		for(int i=1;i<=n;i++)
		{
			sum=a[i].a;
			if(sum*i>=l)
			{
				pos=i;
				break;
			}
		}
		if(pos==0)goto fail2;
		sum=0;
		for(int i=pos+1;i<=n;i++)
		{
			sum=a[i].a;
			if(sum*(i-pos)>=r)
			{
				puts("Yes");
				oldp(i-pos,pos);
				for(int j=pos+1;j<=i;j++)oldb(a[j].pos);puts("");
				for(int j=1;j<=pos;j++)oldb(a[j].pos);puts("");
				return 0;
			}
		}
		goto fail2;
	}
	fail2:;
	puts("No");
	return 0;
}