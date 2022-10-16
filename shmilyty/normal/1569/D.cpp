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
int t,n,m,k,ans,a[200001],b[200001],ok1[1000001],ok2[1000001],n1[1000001],n2[1000001];
pair<int,int> p[300001]; 
vector<pair<int,int> > v1,v2;
bool c1(pair<int,int> x,pair<int,int> y)
{
	return x.second<y.second;
}
bool c2(pair<int,int> x,pair<int,int> y)
{
	return x.first<y.first;
}
void solve()
{
	for(int i=1;i<=n;i++)
		ok1[a[i]]=0;
	for(int i=1;i<=m;i++)
		ok2[b[i]]=0;
	for(int i=1;i<=k;i++)
		n1[p[i].first]=n2[p[i].second]=0;
	n=read();
	m=read();
	k=read();
	ans=0;
	v1.clear();
	v2.clear();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		ok1[a[i]]=1;
	}	
	for(int i=1;i<=m;i++)
	{
		b[i]=read();
		ok2[b[i]]=1;
	}
	fill(n1+1,n1+1+n,0);
	fill(n2+1,n2+1+m,0);
	for(int i=1;i<=k;i++)
	{
		int x=read(),y=read();
		p[i]={x,y};
		if(ok1[x]&&ok2[y])
			continue;
		if(ok1[x])
			v1.push_back(p[i]);
		else
			v2.push_back(p[i]);
	}
	sort(v1.begin(),v1.end(),c1);
	sort(v2.begin(),v2.end(),c2);
	int sz=v1.size(),cnt=0,pre=-1;
	for(int i=1;i<=m;i++)
	{
		int now=pre+1;
		cnt=0;
		while(now<sz&&v1[now].second<b[i])
		{
			ans+=(cnt-n1[v1[now].first]);
			n1[v1[now].first]++;
			cnt++;
			now++;
		}
		for(int l=pre+1;l<now;l++)
			n1[v1[l].first]=0;
		while(now<sz&&v1[now].second==b[i])
			now++;
		now--;
		pre=now;
	}
	cnt=0;
	for(int i=pre+1;i<sz;i++)
	{
		ans+=(cnt-n1[v1[i].first]);
		n1[v1[i].first]++;
		cnt++;
	}
	sz=v2.size(),cnt=0,pre=-1;
	for(int i=1;i<=n;i++)
	{
		int now=pre+1;
		cnt=0;
		while(now<sz&&v2[now].first<a[i])
		{
			ans+=(cnt-n2[v2[now].second]);
			n2[v2[now].second]++;
			cnt++;
			now++;
		}
		for(int l=pre+1;l<now;l++)
			n2[v2[l].second]=0;
		while(now<sz&&v2[now].first==a[i])
			now++;
		now--;
		pre=now;
	}
	cnt=0;
	for(int i=pre+1;i<sz;i++)
	{
		ans+=(cnt-n2[v2[i].second]);
		n2[v2[i].second]++;
		cnt++;
	}
	cout<<ans<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}