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
int n,m,ans,c[10001],r[10001],s[10001];
vector<int> v[100001];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		c[i]=read()+20000;
		r[i]=read();
		s[i]=-1;
		for(int l=c[i]-r[i];l<=c[i]+r[i];l++)
			v[l].push_back(i);
	}
	m=read();
	for(int i=1;i<=m;i++)
	{
		int x=read()+20000,y=read();
		for(auto l:v[x])
			if(s[l]==-1)
				if(y*y+(x-c[l])*(x-c[l])<=r[l]*r[l]) 
                {
                	s[l]=i;
                	ans++;
				}
	} 
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
		cout<<s[i]<<" ";
	return 0;
}