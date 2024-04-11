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
int t,n,m,a[501][501];
void solve()
{
	n=read();
	m=read();
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)	
	{
		string s;
		cin>>s;
		for(int l=1;l<=m;l++)
			a[i][l]=(s[l-1]=='X'?1:0);
	}
	for(int i=1;i<n;i++)
	{
		if(i%3==1)
			for(int l=1;l<=m;l++)
				a[i][l]=1;
		if(i%3==2)
		{
			int to=1;
			for(int l=1;l<=m;l++)
				if(a[i][l]||a[i+1][l])
				{
					to=l;
					break;
				}
			a[i][to]=a[i+1][to]=1;
			i++;
		}	
	}
	if(n%3==0)
		for(int i=1;i<=m;i++)
			if(a[n][i])
				a[n-1][i]=1;
	if(n%3==1)
		for(int i=1;i<=m;i++)
			a[n][i]=1; 
	for(int i=1;i<=n;i++)
	{
		for(int l=1;l<=m;l++)
			cout<<(a[i][l]?'X':'.');
		cout<<endl;
	}
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}