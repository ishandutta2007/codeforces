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
int n,k,a,b,c;
vector<int> v;
int query(int x,int y,int t)
{
	cout<<(t?"or ":"and ");
	cout<<x<<" "<<y<<endl;
	cout.flush();
	return read();
}
int sum(int x,int y)
{
	return query(x,y,1)+query(x,y,0);
}
signed main()
{
	n=read();
	k=read();
	a=sum(1,2);
	b=sum(1,3);
	c=sum(2,3);
	int x=(a+b+c)/2-c;
	v.push_back(x);
	v.push_back(a-x);
	v.push_back(b-x);
	for(int i=4;i<=n;i++)
		v.push_back(sum(1,i)-x);
	sort(ALL(v));
	cout<<"finish "<<v[k-1]<<endl; 
	return 0;
}