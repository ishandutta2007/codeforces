#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0,flag=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			flag=0;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
    return (flag?x:~(x-1));
}
struct node{
	int a[8];
} p[100001];
int n,m,k,f[100001][1<<7];
bool cmp(node x,node y)
{
	return x.a[0]>y.a[0];
}
signed main()
{
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=n;i++)
		p[i].a[0]=read();
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
			p[i].a[l]=read();
	sort(p+1,p+1+n,cmp);
	memset(f,-1,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int l=0;l<(1<<m);l++)
		{
			if(i-__builtin_popcount(l)-1<k)
			{
				if(f[i-1][l]!=-1)
					f[i][l]=f[i-1][l]+p[i].a[0];
			}
			else
				f[i][l]=f[i-1][l];
			for(int j=1;j<=m;j++)
				if((l&(1<<(j-1)))&&f[i-1][l-(1<<(j-1))]!=-1)
					f[i][l]=max(f[i][l],f[i-1][l-(1<<(j-1))]+p[i].a[j]);
		}
	cout<<f[n][(1<<m)-1];
	return 0;
}