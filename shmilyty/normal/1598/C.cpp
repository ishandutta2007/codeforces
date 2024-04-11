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
int t,n,sum,ans,a[200001];
map<int,int> mp;
void solve()
{
	n=read();
	mp.clear();
	sum=0;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		mp[a[i]]++;
		sum+=a[i];
	}
	int g=__gcd(n,sum);
	if(n>2*g)
	{
		puts("0");
		return ;
	}
	for(auto i:mp)
		if(i.first*n<sum)
			ans+=i.second*mp[2*sum/n-i.first];
		elif(i.first*n==sum)
			ans+=i.second*(i.second-1)/2;
	cout<<ans<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve(); 
	return 0;
}