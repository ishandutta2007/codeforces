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
int t,n,a[101][101];
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;i++)
			for(int l=1;l<=n;l++)
				a[i][l]=0;
		for(int i=1;i<=n;i++)
			for(int l=0;l<(n-1)/2;l++)
			{
				a[i][(i+l)%n+1]=1;
				a[(i+l)%n+1][i]=-1;
			}
		for(int i=1;i<=n;i++)
			for(int l=i+1;l<=n;l++)
				cout<<a[i][l]<<" ";
		cout<<endl;
	}
	return 0;
}