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
int t,n,f[1000001][3];
string s;
bool judge(int x)
{
	for(int i=x;i<=n;i++)
	{
		int a=f[i][0]-f[i-x][0],b=f[i][1]-f[i-x][1],c=f[i][2]-f[i-x][2];
		if(a>b&&a>c)
			return 1;
	}
	return 0;
}
void solve()
{
	n=read();
	cin>>s;
	for(int i=0;i<n;i++)
	{
		for(int l=0;l<3;l++)
			f[i+1][l]=f[i][l];
		f[i+1][s[i]-'a']=f[i][s[i]-'a']+1;
	}
	//accabba
	for(int i=2;i<=min(10ll,n);i++)
		if(judge(i))
		{
			printf("%lld\n",i);
//			cout<<i<<endl;
			return ;
		}
	puts("-1");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}