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
int t,a,b,c,pri[1000001];
vector<int> v;
void solve()
{
	a=read();
	b=read();
	c=read();
	if(c==1)
	{
		if(__gcd(a,b)==min(a,b)&&a!=b)
			puts("YES");
		else	
			puts("NO");
		return ;
	}
	int sum=0,x=1;
	for(int i=0;v[i]*v[i]<=a&&i<v.size();i++)
		if(a%v[i]==0)
			while(a%v[i]==0)
			{
				a/=v[i];
				sum++;
			}
	if(a!=1)
		sum++;
	for(int i=0;v[i]*v[i]<=b&&i<v.size();i++)
		if(b%v[i]==0)
			while(b%v[i]==0)
			{
				b/=v[i];
				sum++;
			}
	if(b!=1)
		sum++;
//	cout<<sum<<endl;
	if(sum>=c)
		puts("YES");
	else
		puts("NO");	
}
signed main()
{
	for(int i=2;i<=1000000;i++)
		if(!pri[i])
		{
			v.push_back(i);
			for(int l=i*2;l<=1000000;l+=i)
				pri[l]=1;
		}
	t=read();
	while(t--)
		solve();
	return 0;
}