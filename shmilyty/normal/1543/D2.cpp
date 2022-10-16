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
int t,n,k;
vector<int> v; 
int query(int x)
{
	cout<<x<<endl;
	cout.flush();
	int y=read();
	return y;
}
int XR(int x,int y)
{
	v.clear();
	int ans=0;
	while(x!=0||y!=0)
	{
		v.push_back((x%k+y%k)%k);
		x/=k;
		y/=k;
	}
	reverse(v.begin(),v.end());
	for(int i:v)
		ans=ans*k+i;
	return ans;
}
int NXR(int x,int y)
{
	v.clear();
	int ans=0;
	while(x!=0||y!=0)
	{
		v.push_back((x%k+k-y%k)%k);
		x/=k;
		y/=k;
	}
	reverse(v.begin(),v.end());
	for(int i:v)
		ans=ans*k+i;
	return ans;
}
void solve()
{
	n=read();
	k=read();
	int tot=0;
	for(int i=0;i<n;i++)
	{
		int out;
		if(i&1)
			out=NXR(tot,i);
		else
			out=XR(tot,i); 
		int x=query(out);
		if(x==1)
			return ;
		if(x==-1)
			exit(0);
		tot=NXR(out,tot);
	}
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}