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
int n,k,a[10001],vis[101],bound[101];
pair<int,int> p[101];
vector<int> v[101];
signed main()
{
	n=read();
	k=read();
	for(int i=1;i<=n*k;i++)
	{
		a[i]=read();
		v[a[i]].push_back(i); 
	}
	for(int i=0;i<n;i++)
		bound[i%(k-1)]++;
	for(int i=0;i<k-1;i++)
	{
		vector<pair<int,int> >all;
		for(int l=1;l<=n;l++)
			if(!vis[l])
				all.push_back({v[l][i+1],l});
		sort(all.begin(),all.end());
		for(int l=0;l<bound[i];l++)
		{
			int x=all[l].second;
			p[x].first=v[x][i];
			p[x].second=v[x][i+1];
			vis[x]=1;
		}
	}
	for(int i=1;i<=n;i++)
		cout<<p[i].first<<" "<<p[i].second<<endl;
	return 0;
}