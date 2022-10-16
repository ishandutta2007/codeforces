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
int n,l,r,mid;
int ask(int x,int y)
{
	cout<<"? "<<x<<" "<<y<<endl; 
	cout.flush();
	int a;
	cin>>a;
	return a;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	l=1;
	r=n;
	mid=(l+r)>>1;
	int x=ask(l,r);
	if(x==1||ask(1,x)!=x)
	{
		l=x;
		while(r-l>1)
		{
			mid=(l+r)>>1;
			if(ask(x,mid)==x)
				r=mid;
			else
				l=mid;
		}
		cout<<"! "<<r<<endl;
	}
	else
	{
		r=x;
		while(r-l>1)
		{
			mid=(l+r)>>1;
			if(ask(mid,x)==x)
				l=mid;
			else
				r=mid;
		}
		cout<<"! "<<l<<endl;
	}
	return 0;
}