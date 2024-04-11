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
struct node{
	int val,a1,a2;
};
int t,n,m,b[101][101],ans[101][101];
vector<node> v; 
bool cmp(node x,node y)
{
	return x.val<y.val;
}
void solve()
{
	n=read();
	m=read();
	v.clear();
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
		{
			b[i][l]=read();
			ans[i][l]=0;
			v.push_back((node){b[i][l],i,l});
		}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<m;i++)
	{
		ans[v[i].a1][i+1]=v[i].val;
		b[v[i].a1][v[i].a2]=0;
	}
	for(int i=1;i<=n;i++)
	{
		int cnt=1;
		for(int l=1;l<=m;l++)
			if(b[i][l])
			{
				while(ans[i][cnt])
					cnt++;
				ans[i][cnt]=b[i][l];
			}
		for(int l=1;l<=m;l++)
			cout<<ans[i][l]<<" ";
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