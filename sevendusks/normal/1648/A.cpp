/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=1e5+100;
int n,m,b[N],w;
vector <int> a[N];
vector <pair<int,int> > p[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
long long solve(vector<pair<int,int> > v)
{
	sort(v.begin(),v.end());
	long long ans=0,sum=0,cnt=0;
	for (auto [x,y]:v)
	{
		ans+=cnt*x-sum;
		sum+=x;cnt++;
	}
	for (auto &[x,y]:v) swap(x,y);
	sort(v.begin(),v.end());
	sum=cnt=0;
	for (auto [x,y]:v)
	{
		ans+=cnt*x-sum;
		sum+=x;cnt++;
	}
	return ans;
}
signed main()
{
	n=read();m=read();
	for (int i=1;i<=n;i++)
	{
		a[i].resize(m+1);
		for (int j=1;j<=m;j++) a[i][j]=read(),b[++w]=a[i][j];
	}
	sort(b+1,b+1+w);w=unique(b+1,b+1+w)-b-1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			int pos=lower_bound(b+1,b+1+w,a[i][j])-b;
			p[pos].emplace_back(i,j);
		}
	}
	long long ans=0;
	for (int i=1;i<=w;i++) ans+=solve(p[i]);
	printf("%lld\n",ans);
}