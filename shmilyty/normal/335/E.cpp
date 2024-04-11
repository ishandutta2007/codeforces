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
int n,h;
string s;
signed main()
{
	cin>>s;
	n=read();
	h=read();
	if(s[0]=='B')
	{
		cout<<n;
		return 0;
	}
	double ans=n;
	for(int i=1;i<=h;i++)
		for(int l=1;l<n;l++)
		{
			double res=n-l;
			res*=pow((double)1-1.0/(1<<i),l-1)*pow(1.0/(1<<i),2);
			res*=((1<<i)-(1<<(i-1))*(1+(l-1)*((double)1.0/((1<<i)-1))));
			ans+=res;
		}
	printf("%.12f",ans);
	return 0;
}