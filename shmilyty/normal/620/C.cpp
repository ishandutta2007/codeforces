#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
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
int n,last=1,a[300001];
set<int> s;
vector<pair<int,int> > v;
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(s.count(a[i]))
		{
			v.push_back({last,i});
			last=i+1;
			s.clear();
			continue;
		}
		s.insert(a[i]);
	}
	if(!v.size())
	{
		puts("-1");
		return 0;
	}
	v[v.size()-1].second=n;
	cout<<(int)v.size()<<endl;
	for(auto i:v)
		cout<<i.first<<" "<<i.second<<endl;
	return 0;
}