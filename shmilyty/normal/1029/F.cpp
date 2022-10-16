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
int n,m;
vector<int> v;
int solve(int x,int y)
{
	v.clear();
	for(int i=1;i*i<=y;i++)
		if(y%i==0)
			v.push_back(i);
	for(int i=sqrt(x),l=v.size()-1;i;i--)
		if(x%i==0)
		{
			while(v[l]>i)
				l--;
			if(x/i>=y/v[l])
				return 2*(i+x/i);
		}
	return INF;
}
signed main()
{
	n=read();
	m=read();
//	cout<<solve(n+m,n)<<endl<<solve(n+m,m)<<endl;
	cout<<min(solve(n+m,m),solve(n+m,n));
	return 0;
}