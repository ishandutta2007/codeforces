#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	bool flag=1;
	int x=0;
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
int t,n;
vector<int> a,b;
long double ans;
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		ans=0.0;
		a.clear();
		b.clear();
		for(int i=1;i<=2*n;i++)
		{
			int x=read(),y=read();
			if(x==0)
				b.push_back(abs(y));
			else
				a.push_back(abs(x));
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		for(int i=0;i<n;i++)
			ans+=double(sqrt(a[i]*a[i]+b[i]*b[i]));
		cout<<setprecision(15)<<fixed<<ans<<endl;
	}
	return 0;
}