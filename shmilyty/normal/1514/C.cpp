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
int n,cnt,sum=1,ok[100001];
void solve()
{
	n=read();
	for(int i=1;i<n;i++)
		if(__gcd(i,n)==1)
		{
			(sum*=i)%=n;
			cnt++;
			ok[i]=1;
		}
	if(sum!=1)
	{
		cnt--;
		ok[sum]=0;
	}
	cout<<cnt<<endl;
	for(int i=1;i<n;i++)
		if(ok[i])
			cout<<i<<" ";
}
signed main()
{
	solve();
	return 0;
}