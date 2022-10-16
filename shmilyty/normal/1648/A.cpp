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
int n,m,ans;
vector<int> v[200001]; 
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		for(int l=1;l<=m;l++)
		{
			int x=read();
			v[x*2-1].push_back(i);
			v[x*2].push_back(l);
		}
	for(int i=1;i<=200000;i++)
	{
		sort(ALL(v[i]));
		int tot=0,cnt=0;
		for(int l:v[i])
		{
			ans+=l*cnt-tot;
			tot+=l;
			cnt++;
		}
	}
	cout<<ans;
	return 0;
}