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
int t,n,lim,sum,a[101];
void solve()
{
	n=read();
	lim=read();
	sum=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		sum+=a[i];	
	}
	if(sum==lim)
	{
		puts("NO");
		return ;
	}
	sort(a+1,a+1+n,greater<int>());
	int cnt=0;
	puts("YES");
	for(int i=1;i<=n;i++)
	{
		if(cnt+a[i]==lim)
			swap(a[i],a[i+1]);
		cnt+=a[i]; 
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return ;
}
signed main()
{
	t=read();
	while(t--)
		solve(); 
	return 0;
}