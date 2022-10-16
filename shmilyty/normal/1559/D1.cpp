#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
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
int n,m1,m2,f1[100001],f2[100001];
vector<pair<int,int> > v;
int fi1(int x)
{
	return f1[x]==x?x:f1[x]=fi1(f1[x]);
}
int fi2(int x)
{
	return f2[x]==x?x:f2[x]=fi2(f2[x]);
}
signed main()
{
	n=read();
	m1=read();
	m2=read();
	for(int i=1;i<=n;i++)
		f1[i]=f2[i]=i;
	while(m1--)
	{
		int x=read(),y=read();
		f1[fi1(x)]=fi1(y);
	}
	while(m2--)
	{
		int x=read(),y=read();
		f2[fi2(x)]=fi2(y);
	}
	for(int i=1;i<=n;i++)
		for(int l=i+1;l<=n;l++)
			if(fi1(i)!=fi1(l)&&fi2(i)!=fi2(l))
			{
				f1[fi1(i)]=fi1(l);
				f2[fi2(i)]=fi2(l);
				v.push_back({i,l});
			}
	cout<<(int)v.size()<<endl;
	for(pair<int,int> i:v)
		cout<<i.first<<" "<<i.second<<endl;
	return 0;
}