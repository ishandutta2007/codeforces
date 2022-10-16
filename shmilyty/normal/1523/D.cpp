#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
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
int n,m,pp,best,ans[100],a[200001],p[200001];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	srand((unsigned long long)new char^time(0));
	cin>>n>>m>>pp;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		for(int l=0;l<m;l++)
			if(s[l]=='1')
				a[i]|=(1ll<<l);	
	} 
	for(int i=1;i<=n;i++)
		p[i]=i;
	random_shuffle(p+1,p+n+1);
	for(int i=1;i<=min(200ll,n);i++)
	{
		int x=p[i];
		vector<int> v;
		for(int l=0;l<m;l++)
			if((a[x]>>l)&1)
				v.push_back(l);
		int sz=(int)(v.size());
		vector<int> b(1<<sz);
		for(int l=1;l<=n;l++)
		{
			int u=0;
			for(int j=0;j<sz;j++)
				if((a[l]>>v[j])&1)
					u|=(1<<j);
			b[u]++;
		}
		for(int l=0;l<sz;l++)
			for(int j=0;j<(1<<sz);j++)
				if(j&(1<<l))
					b[j^(1<<l)]+=b[j];
		for(int l=0;l<(1<<sz);l++)
			if(2*b[l]>=n&&(long long)__builtin_popcount(l)>best)
			{
				best=(long long)__builtin_popcount(l);
				memset(ans,0,sizeof(ans));
				for(int j=0;j<sz;j++)
					if(l&(1<<j))
						ans[v[j]]=1;
			}
	}
	for(int i=0;i<m;i++)
		cout<<ans[i];
	return 0;
}