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
int n,d,a[100001],g[100001][10];
vector<int> ans;
double f[100001][10];
signed main()
{
	n=read();
	d=read();
	memset(g,-1,sizeof(g));
	fill(f[0],f[0]+10,-1e300);
	f[0][1]=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		for(int l=0;l<10;l++)
			f[i][l]=f[i-1][l];
		for(int l=0;l<10;l++)
			if(f[i-1][l]+log(a[i])>f[i][a[i]*l%10])
			{
				f[i][a[i]*l%10]=f[i-1][l]+log(a[i]);
				g[i][a[i]*l%10]=l;
			}
	}
	int cnt=d,now=n;
	while(now)
	{
		if(g[now][cnt]!=-1)
		{
			ans.push_back(a[now]);
			cnt=g[now][cnt];
		}
		now--;
	}
	if(ans.size()==0)
		puts("-1");
	else
		cout<<ans.size()<<endl;
	for(int i:ans)
		cout<<i<<" ";
	return 0;
}