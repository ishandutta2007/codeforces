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
int t,n,k,one;
multiset<int> s;
void solve()
{
	n=read();
	k=read();
	if(k==1)
	{
		cout<<n<<endl;
		return ;
	}
	s.clear();
	one=n%10;
	n/=10;
	for(int i=10;n;i*=10,n/=10)
		for(int l=1;l<=n%10;l++)
			s.insert(i);
	while(s.size()+one<k)
	{
		int x=(*s.begin());
		s.erase(s.begin());
		if(x==10)
		{
			one+=10;
			continue;
		}
		for(int i=1;i<=10;i++)
			s.insert(x/10);
	}
	if(s.size()+one>=k)
	{
		while(one--)
			s.insert(1);
		while(s.size()>k)
		{
			auto i=s.begin(),l=s.begin();
			i++;
			s.erase(i);
			s.erase(l);
			s.insert((*i)+(*l));
		}
		for(int i:s)
			cout<<i<<" ";
		return ;
	}
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}