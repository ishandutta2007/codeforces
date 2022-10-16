#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
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
int t,n,f[500001];
string s;
map<pair<int,int>,int> last;
void solve()
{
	n=read();
	cin>>s;
	last.clear();
	int n1=0,n2=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='D')
			n1++;
		else
			n2++;
		int x1,x2,g=__gcd(n1,n2);
		if(n1==0||n2==0)
		{
			x1=(n1>0);
			x2=(n2>0);
		}
		else
		{
			x1=n1/g;
			x2=n2/g;
		}
//		cout<<n1<<" "<<n2<<" "<<x1<<" "<<x2<<endl;
		if(last[{x1,x2}])
			f[i]=f[last[{x1,x2}]-1]+1;
		else
			f[i]=1;
		last[{x1,x2}]=i+1;
		cout<<f[i]<<" ";
	}
	cout<<endl;
}
signed main()
{
	t=read();
	while(t--)	
		solve();
	return 0;
}