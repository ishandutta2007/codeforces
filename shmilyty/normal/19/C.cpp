#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
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
map<int,std::vector<int> >mp;
priority_queue<pair<int,int>> q;
int n,ans=-1,a[100001],hsh[100001],bse[100001];
const int mod=1e9+9;
int query(int l,int r)
{
	return (hsh[r]-hsh[l]*bse[r-l]%mod+mod)%mod;
}
signed main()
{
	n=read();
	bse[0]=1;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		bse[i]=bse[i-1]*31%mod;
		hsh[i]=(hsh[i-1]*31+a[i])%mod;
		for(int l:mp[a[i]])
		{
			// cout<<l<<" "<<i<<" "<<query(l,i)<<" "<<query(l+l-i,l)<<endl;
			if(l+1>=i-l&&query(l,i)==query(l+l-i,l))
				q.push({l-i,i-1-l-l});
		}
		mp[a[i]].push_back(i);
	}
	while(!q.empty())
	{
		// cout<<q.top().first<<" "<<q.top().second<<endl;
		if(q.top().second<=ans)
			ans=q.top().first+q.top().second;
		q.pop();
	}
	cout<<n+ans+1<<'\n';
	for(ans=-ans;ans<=n;ans++)
		cout<<a[ans]<<" ";
	return 0;
}