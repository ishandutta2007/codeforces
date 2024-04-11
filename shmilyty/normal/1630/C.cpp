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
int n,cnt,ans,a[200001],L[200001],R[200001];
array<int,2>b[200001];
void dfs(int x,bool y)
{
	if(x>cnt)
		return ;
	if(y)
		ans+=b[x][1]-b[x][0]-1;
	int k=x,maxx=0,pos=0;
	while(k<cnt)
	{
		if(b[k+1][0]>b[x][1])
			break;
		if(b[k+1][1]>maxx)
		{
			maxx=b[k+1][1];
			pos=k+1;
		}
		k++;
	}
	if(pos>x&&maxx>b[x][1])
	{
		ans+=maxx-b[x][1]-1;
		dfs(pos,0);
	}
	else
		dfs(k+1,1);
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int x=read();
		if(!L[x])
			L[x]=i;
		R[x]=i;
	}
	for(int i=1;i<=n;i++)
		if(L[i]<R[i])
			b[++cnt]={L[i],R[i]};
	sort(b+1,b+1+cnt);
	dfs(1,1);
	cout<<ans;
	return 0;
}