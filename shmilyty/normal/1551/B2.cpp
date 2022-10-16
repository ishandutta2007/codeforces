#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
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
int t,n,k,a[200001],num[200001],ans[200001];
vector<int> v;
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
void solve()
{
	n=read();
	k=read();
	v.clear();
	for(int i=1;i<=n;i++)
		num[i]=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		ans[i]=0;
		num[a[i]]=min(num[a[i]]+1,k);
	}
	for(int i=1;i<=n;i++)
		if(num[a[i]])
		{
			num[a[i]]--;
			v.push_back(i);
		}
	sort(v.begin(),v.end(),cmp);
	v.resize(v.size()/k*k);
	for(int i=0;i<v.size();i++)
		ans[v[i]]=i%k+1;
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}