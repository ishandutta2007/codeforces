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
int t,n,l,r,ans,b[200001];
set<int> s;
void solve()
{
	n=read();
	s.clear();
	ans=1;
	for(int i=1;i<=n;i++)
	{
		b[i]=read();
		set<int>::iterator up=s.upper_bound(b[i-1]);
		set<int>::iterator down=s.lower_bound(b[i-1]);
		if(up==s.end())
			r=114514114514114514;
		else
			r=*up;
		if(down==s.begin())
			l=-114514114514114514;
		else
		{
			down--;
			l=*down;
		}
//		cout<<l<<" "<<r<<" "<<b[i]<<endl;
		if(l>b[i]||r<b[i])
			ans=0;
		s.insert(b[i]);
	}
	if(ans)
		puts("Yes");
	else
		puts("No");
}
signed main()
{
	t=read();
	while(t--)
		solve(); 
	return 0;
}