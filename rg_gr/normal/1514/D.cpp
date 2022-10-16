// Problem: AT1219 
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/AT1219
// Memory Limit: 500 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <bits/extc++.h>
using namespace __gnu_pbds;
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
inline int re1d()
{
	char c=getchar();//
	while(c<48||c>49)c=getchar();
	return c&1;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
struct Queries{
	int l,r,lb,rb,i;
	bool operator<(const Queries &b)const
	{
		return lb==b.lb?((lb&1)?r<b.r:r>b.r):lb<b.lb;
	}
}q[300005];
int a[300005],c[300005],t[300005],b[300005];
const int B=600;
int ans=0;
inline void add(int x)
{
	t[b[a[x]]]--,a[x][b]++,t[a[x][b]]++,ans=max(ans,a[x][b]);
}
inline void del(int x)
{
	t[b[a[x]]]--,a[x][b]--,t[a[x][b]]++;
	if(t[ans]==0)ans--;
}
signed main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)q[i].i=i,q[i].l=read(),q[i].r=read(),q[i].lb=q[i].l/B,q[i].rb=q[i].r/B;
	std::sort(q+1,q+1+m);q[0].lb=-1;
	int cl=1,cr=0;
	for(int i=1;i<=m;i++)
	{
		int l=q[i].l,r=q[i].r,lb=q[i].lb,rb=q[i].rb;
		while(cl>l)add(--cl);
		while(cr<r)add(++cr);
		while(cl<l)del(cl++);
		while(cr>r)del(cr--);
		if(ans>(r-l+2)/2)c[q[i].i]=ans+ans-r+l-1;
		else c[q[i].i]=1;
	}
	for(int i=1;i<=m;i++)printf("%d\n",c[i]);
}