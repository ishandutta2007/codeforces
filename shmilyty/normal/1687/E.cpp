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
int n,ans,tot=2,a[100010],p[100010],s[100010];
std::vector<int> V,b[100010];
void out(vector<int> v,bool rev)//0:  1: flip
{
	int S=v.size();
	for(int i=1;i<(1<<S);i++)
	{
		int x=__builtin_popcount(i);
		cout<<((x&1)^rev^1)<<" "<<x<<" ";
		for(int l=0;l<S;l++)
			if((i>>l)&1)
				cout<<v[l]<<" ";
		cout<<'\n';
	}
}
std::vector<int> fnd(int bse,int x)
{
	std::vector<int> res;
	res.push_back(x%n+1);
	int cnt=a[x%n+1];
	for(int i=2;i<=cnt;i++)
		if(cnt%i==0)
		{
			int p1=1,p2=1;
			while(cnt%i==0)
			{
				p1*=i;
				cnt/=i;
			}
			while(bse%i==0)
			{
				p2*=i;
				bse/=i;
			}
			if(p1!=p2)
			{
				for(int l=1;l<=n;l++)
					if(l!=x&&(a[l]/p2)%i)
					{
						res.push_back(l);
						cnt=__gcd(cnt,a[l]);
						break;
					}
			}
			if(i<cnt&&i>cnt/i)
				i=cnt-1;
		}
	sort(ALL(res));
	return res;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		p[i]=__gcd(p[i-1],a[i]);
	for(int i=n;i;i--)
		s[i]=__gcd(s[i+1],a[i]);
	V=fnd(p[n],0);
	// cout<<V.size()<<'\n';
	// for(int i:V)
	// 	cout<<i<<" ";
	// cout<<'\n';
	for(int i=1;i<=n;i++)
		if(__gcd(p[i-1],s[i+1])!=p[n])
		{
			b[i]=fnd(__gcd(p[i-1],s[i+1]),i);
			ans+=(1<<(b[i].size()))-1;
			tot--;
		}
	// cout<<ans<<'\n';
	// system("pause");
	cout<<ans+abs(tot)*((1<<(V.size()))-1)<<'\n';
	if(tot>0)
		for(int i=1;i<=tot;i++)
			out(V,0);
	else
		for(int i=1;i<=-tot;i++)
			out(V,1);
	for(int i=1;i<=n;i++)
		if(b[i].size())
			out(b[i],0);
	return 0;
}