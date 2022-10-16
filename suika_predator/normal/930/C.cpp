#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m,s,e;
int a[233333],ra[233333];
int lis[233333],rlis[233333];
int maxx=0;
int st[233333];
int top=0;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&s,&e);
		a[s]++;a[e+1]--;
	}
	for(int i=1;i<=m;i++)a[i]+=a[i-1],ra[m-i+1]=a[i];
//	for(int i=1;i<=m;i++)cout<<ra[i]<<' ';cout<<endl;
	memset(st,0x3f,sizeof(st));
	st[0]=0;
	for(int i=1;i<=m;i++)
	{
		int l=0,r=m;
		while(l<r)
		{
			int x=(l+r+1)>>1;
			if(st[x]<=a[i])l=x;
			else r=x-1;
		}
		lis[i]=l+1;
		st[l+1]=min(st[l+1],a[i]);
	}
//	for(int i=1;i<=m;i++)cout<<lis[i]<<' ';cout<<endl;
	memset(st,0x3f,sizeof(st));
	st[0]=0;
	for(int i=1;i<=m;i++)
	{
		int l=0,r=m;
		while(l<r)
		{
			int x=(l+r+1)>>1;
			if(st[x]<=ra[i])l=x;
			else r=x-1;
		}
		rlis[i]=l+1;
		st[l+1]=min(st[l+1],ra[i]);
	}
//	for(int i=1;i<=m;i++)cout<<rlis[i]<<' ';cout<<endl;
	int ans=0;
	for(int i=1;i<=m;i++)ans=max(ans,lis[i]+rlis[m-i+1]-1);
	printf("%d\n",ans);
	return 0;
}