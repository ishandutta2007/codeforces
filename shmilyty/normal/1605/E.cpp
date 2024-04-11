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
int n,q,tot,s1[200001],s2[200001],s3,a[200001],b[200001],p[200001],f[200001],isp[200001];
vector<int> v,v1,v2;
void solve()
{
	b[1]=read();
	int ans=0;
	fill(f+1,f+1+n,0);
	for(int i=1;i<=n;i++)
		for(int l=i;l<=n;l+=i)
			f[l]+=p[l/i]*(b[i]-a[i]);
	for(int i=1;i<=n;i++)
		ans+=abs(f[i]);
	cout<<ans<<endl;
}
signed main()
{
	p[1]=1;
	for(int i=2;i<=2e5;i++)
	{
		if(!isp[i])
		{
			v.push_back(i);
			p[i]=-1;
		}
		for(int l:v)
		{
			if(l*i>2e5)
				break;
			isp[l*i]=1;
			if(i%l==0)
			{
				p[l*i]=0;
				break;
			}
			p[l*i]=-p[i];
		}
	}
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		b[i]=read();
	b[1]=0;
	for(int i=2;i<=n;i++)
		for(int l=i;l<=n;l+=i)
			f[l]+=p[l/i]*(b[i]-a[i]);
	for(int i=2;i<=n;i++)
		if(p[i]==-1)
			v1.push_back(f[i]);
		elif(p[i]==1)
			v2.push_back(f[i]);
		else
			s3+=abs(f[i]);
	sort(ALL(v1));
	sort(ALL(v2));
	for(int i=0;i<v1.size();i++)
		s1[i+1]=s1[i]+v1[i];
	for(int i=0;i<v2.size();i++)
		s2[i+1]=s2[i]+v2[i];
	q=read();
	while(q--)
	{
		int x=read()-a[1],ans=abs(x);
		int y=lower_bound(v1.begin(),v1.end(),x)-v1.begin();
		ans+=x*y-2*s1[y]+s1[v1.size()]-x*(v1.size()-y);
		int z=lower_bound(v2.begin(),v2.end(),-x)-v2.begin();
		ans+=-x*z-2*s2[z]+s2[v2.size()]+x*(v2.size()-z);
		cout<<ans+s3<<endl;
	}
//		solve();
	return 0;
}