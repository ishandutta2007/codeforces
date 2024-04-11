#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	bool flag=1;
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int n,m,k,cnt,f[501][501][11],v[501][501][4];
int px[]={1,0,-1,0};
int py[]={0,1,0,-1};
bool ok(int x,int y)
{
	return (x>=1&&x<=n&&y>=1&&y<=m);
}
signed main()
{
	n=read();
	m=read();
	k=read();
	if(k&1)
	{
		for(int i=1;i<=n;i++)
		{
			for(int l=1;l<=m;l++)
				cout<<"-1 ";
			cout<<endl;
		}
		return 0;
	}
	k/=2;
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
			for(int j=0;j<4;j++)
				v[i][l][j]=114514114514114514;
	for(int i=1;i<=n;i++)
		for(int l=1;l<m;l++)
			v[i][l][1]=v[i][l+1][3]=read();
	for(int i=1;i<n;i++)
		for(int l=1;l<=m;l++)
			v[i][l][0]=v[i+1][l][2]=read();
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
		{
			f[i][l][1]=114514114514114514;
			for(int j=0;j<4;j++)
				f[i][l][1]=min(f[i][l][1],v[i][l][j]);
		}
	for(int q=2;q<=k;q++)
		for(int i=1;i<=n;i++)
			for(int l=1;l<=m;l++)
			{
				f[i][l][q]=114514114514114514;
				for(int j=0;j<4;j++)
					if(ok(i+px[j],l+py[j]))
						f[i][l][q]=min(f[i][l][q],v[i][l][j]+f[i+px[j]][l+py[j]][q-1]);
			}
	for(int i=1;i<=n;i++)
	{
		for(int l=1;l<=m;l++)
			cout<<2*f[i][l][k]<<" ";
		cout<<endl;
	}
		
	return 0;
}