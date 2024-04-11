#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
map<pair<double,pair<double,double> >,double> mp;
double ep=1e-15;
int t,n;
double A,B,C,k;
double dfs(double x,double y,double z)
{
	if(mp[{x,{y,z}}])
		return mp[{x,{y,z}}];
	double res=z,xx,yy,zz;
	if(x!=0)
	{
		if(y!=0)
			res+=(dfs(max(0.0,x-k-ep),y+min(x,k)/2.0,z+min(x,k)/2.0)+1)*x;
		else
			res+=(dfs(max(0.0,x-k-ep),0.0,z+min(x,k))+1)*x;
	}
	if(y!=0)
	{
		if(x!=0)
			res+=(dfs(x+min(y,k)/2.0,max(0.0,y-k-ep),z+min(y,k)/2.0)+1)*y;
		else
			res+=(dfs(0.0,max(0.0,y-k-ep),z+min(y,k))+1)*y;
	}
//	cout<<x<<" "<<y<<" "<<z<<" "<<res<<endl;
	return mp[{x,{y,z}}]=res;
}
void solve()
{
	cin>>A>>B>>C>>k;
	printf("%.10f\n",dfs(A,B,C));
//	cout<<dfs(A,B,C)<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}