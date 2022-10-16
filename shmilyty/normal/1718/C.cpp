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
// const int INF=4e18;
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
int t,n,q,a[200001],f[200001][41];
std::vector<int> v;
multiset<int> s;
void solve()
{
	n=read();
	q=read();
	v.clear();
	int nn=n;
	for(int i=2;i*i<=nn;i++)
		if(nn%i==0)
		{
			while(nn%i==0)
				nn/=i;
			v.push_back(i);
			v.push_back(n/i);
		}
	if(nn!=n&&nn!=1)
	{
		v.push_back(nn);
		v.push_back(n/nn);
	}
	v.push_back(1);
	for(int i=0;i<n;i++)
		a[i]=read();
	for(int l=0;l<v.size();l++)
		for(int i=0;i<v[l];i++)
			f[i][l]=0;
	for(int l=0;l<v.size();l++)
		for(int i=0;i<n;i++)
			f[i%v[l]][l]+=a[i];
	s.clear(); 
	for(int l=0;l<v.size();l++)
		for(int i=0;i<v[l];i++)
			s.insert(-f[i][l]*v[l]);
	cout<<-(*s.begin())<<'\n';
	while(q--)
	{
		int x=read()-1,y=read();
		for(int l=0;l<v.size();l++)
		{
			int old=f[x%v[l]][l];
			s.erase(s.find(-old*v[l]));
			f[x%v[l]][l]+=y-a[x];
			s.insert(-f[x%v[l]][l]*v[l]);
		}
		a[x]=y;
		cout<<-(*s.begin())<<'\n';
	}
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}