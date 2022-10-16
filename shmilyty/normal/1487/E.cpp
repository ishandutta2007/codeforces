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
int n[4],m;
pair<int,int> a[4][150001];
set<int> s[4][150000];
signed main()
{
	for(int i=0;i<4;i++)
		n[i]=read();
	for(int i=0;i<4;i++)
		for(int l=0;l<n[i];l++)
			a[i][l]=make_pair(read(),l);
	for(int i=0;i<4;i++)
		a[i][n[i]]=make_pair(114514114514114514,n[i]);
	for(int i=1;i<4;i++)
	{
		m=read();
		while(m--)
		{
			int x=read()-1;
			int y=read()-1;
			s[i][y].insert(x);
		}
	}
	sort(a[0],a[0]+n[0]);
	for(int i=1;i<4;i++)
	{
		for(int j=0;j<n[i];j++)
			for(int k=0;;k++)
				if(!s[i][j].count(a[i-1][k].second))
				{
					a[i][j].first+=a[i-1][k].first;
					break;
				}
		sort(a[i],a[i]+n[i]);
	}
	if(a[3][0].first>=114514114514114514)
		cout<<-1;
	else
		cout<<a[3][0].first;
	return 0;
}