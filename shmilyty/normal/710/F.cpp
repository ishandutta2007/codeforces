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
const int M=1e9+7;
int q,n,ans,bse[300001],hsh[300001],vis[300001];
map<int,int> mp[300001];
char s[300001];
std::vector<int> v;
signed main()
{
	bse[0]=1;
	for(int i=1;i<=300000;i++)
		bse[i]=bse[i-1]*1007%M;
	q=read();
	while(q--)
	{
		int opt=read();
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=1;i<=n;i++)
			hsh[i]=(hsh[i-1]*1007+s[i])%M;
		if(opt==1)
		{
			if(!vis[n])
			{
				v.push_back(n);
				vis[n]=1;
			}
			mp[n][hsh[n]]++;
		}
		elif(opt==2)
			mp[n].erase(hsh[n]);
		else
		{
			ans=0;
			for(int i:v)
				for(int l=i;l<=n;l++)
					if(mp[i].find(((hsh[l]-hsh[l-i]*bse[i]%M+M)%M))!=mp[i].end())
						ans++;
			cout<<ans<<endl;
		}
		// cout<<mp[3].size()<<endl;
	}
	return 0;
}