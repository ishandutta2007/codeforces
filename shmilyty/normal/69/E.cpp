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
int n,k,a[100001];
map<int,int> num;
set<int> s;
void add(int x,int v)
{
	num[x]+=v;
	if(num[x]==1)
		s.insert(-x);
	else
		s.erase(-x);
}
signed main()
{
	n=read();
	k=read();
	for(int i=1;i<k;i++)
		add(a[i]=read(),1);
	for(int i=k;i<=n;i++)
	{
		add(a[i]=read(),1);
		if(i!=k)
			add(a[i-k],-1);
		if(s.empty())
			puts("Nothing");
		else
			cout<<-(*s.begin())<<'\n';
	}
	return 0;
}