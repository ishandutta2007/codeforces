#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
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
int n,k,f[200002];
char a[200001];
multiset<int> val,minn;
vector<int> del[200001];
signed main()
{
	n=read();
	k=read();
	scanf("%s",a+1);
	minn.insert(0);
	for(int i=n;i;i--)
	{
		f[i]=f[i+1]+i;
		if(i+k+2<=n+1)
			minn.erase(minn.find(f[i+k+2]));
		for(int l:del[i])
			val.erase(val.find(l));
		if(!val.empty())
			f[i]=min(f[i],*val.begin());
		if(a[i]=='1')
		{
			int v=(minn.empty()?0:*minn.begin())+i;
			f[i]=min(f[i],v);
			val.insert(v);
			if(i-k-1>0)
				del[i-k-1].push_back(v);
		}
		minn.insert(f[i]);
	}
	cout<<f[1];
	return 0;
}