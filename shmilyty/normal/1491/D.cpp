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
int q,a[31],f1[41],f2[41];
void solve()
{
	int x=read(),y=read();
	if(x>y)
	{
		puts("No");
		return ;
	}
	for(int i=1;i<=40;i++)
	{
		f1[i]=x%2;
		x/=2;
	}
	for(int i=1;i<=40;i++)
	{
		f2[i]=y%2;
		y/=2;
	}
		
//	for(int i=1;i<=40;i++)
//		cout<<f1[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=40;i++)	
//		cout<<f2[i]<<" ";
//	cout<<endl;
	int xx=0,yy=0;
	for(int i=1;i<=40;i++)
	{
		xx+=f1[i];
		yy+=f2[i];
		if(xx<yy)
		{
			puts("No");
			return ;
		}
	}
	puts("Yes");
}
signed main()
{
	q=read();
	a[0]=1;
	for(int i=1;i<=30;i++)
		a[i]=a[i-1]*2;
	while(q--)
		solve();
	return 0;
}