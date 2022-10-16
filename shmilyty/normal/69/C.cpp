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
int k,n,m,q,num[101][51],a[101][101];
map<string,int> mp;
string s[101];
vector<pair<string,int>> v;
signed main()
{
	k=read();
	n=read();
	m=read();
	q=read();
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		mp[s[i]]=i;
	}
	for(int i=n+1;i<=n+m;i++)
	{
		char c=getchar();
		while(!isalpha(c))
			c=getchar();
		while(isalpha(c))
		{
			s[i]+=c;
			c=getchar();
		}
		c=getchar();
		c=getchar();
		while(1)
		{
			string ss;
			while(isalpha(c))
			{
				ss+=c;
				c=getchar();
			}
			c=getchar();
			int cnt=0;
			while(isdigit(c))
			{
				cnt=(cnt<<1)+(cnt<<3)+(c-'0');
				c=getchar();
			}
			num[i][mp[ss]]=cnt;
			if(c=='\n')
				break;
			c=getchar();
			c=getchar();
		}
	}
	while(q--)
	{
		int x=read();
		string ss;
		cin>>ss;
		a[x][mp[ss]]++;
		for(int i=n+1;i<=n+m;i++)
		{
			bool ok=1;
			for(int l=1;l<=n;l++)
				if(num[i][l]>a[x][l])
				{
					ok=0;
					break;
				}
			if(!ok)
				continue;
			for(int l=1;l<=n;l++)
				a[x][l]-=num[i][l];
			a[x][i]++;
		}
	}
	for(int i=1;i<=k;i++)
	{
		int ans=0;
		for(int l=1;l<=n+m;l++)
			if(a[i][l])
				ans++;
		cout<<ans<<'\n';
		v.clear();
		for(int l=1;l<=n+m;l++)
			if(a[i][l])
				v.push_back({s[l],a[i][l]});
		sort(ALL(v));
		for(auto l:v)
			cout<<l.first<<" "<<l.second<<'\n';
	}
	return 0;
}