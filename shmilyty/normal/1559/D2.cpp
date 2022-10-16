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
int fi1(int x)
{
	return f1[x]==x?x:f1[x]=fi1(f1[x]);
}
int fi2(int x)
{
	return f2[x]==x?x:f2[x]=fi2(f2[x]);
}
vector<int> v1,v2;
vector<pair<int,int> > ans;
signed main()
{
//	fileio("2");
//	freopen("2.in","r",stdin);
	n=read();
	m1=read();
	m2=read();
	if(n==1)
	{
		puts("0");
		return 0;
	}
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
		if(fi1(i)!=fi1(1)&&fi2(i)!=fi2(1))
		{
			ans.push_back({1,i});
			f1[fi1(i)]=fi1(1);
			f2[fi2(i)]=fi2(1);
		}
	for(int i=1;i<=n;i++)
	{
		if(fi1(i)!=fi1(1))
		{
			v1.push_back(i);
			f1[fi1(i)]=fi1(1);
		}
		if(fi2(i)!=fi2(1))
		{
			v2.push_back(i);
			f2[fi2(i)]=fi2(1);
		}
	}
	for(int i=0;i<min(v1.size(),v2.size());i++)
		ans.push_back({v1[i],v2[i]});
	cout<<(int)ans.size()<<endl;
	for(auto i:ans)
		cout<<i.first<<" "<<i.second<<endl;
	return 0;
}