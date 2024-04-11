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
		x=(x<<1)+(x<<3)+c-'0';//876543219
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int n,l,r;
map<pair<int,int>,int> p;
int ask(int x,int y)
{
	if(p[make_pair(x,y)])
		return p[make_pair(x,y)];
	cout<<"? "<<x<<" "<<y<<endl; 
	cout.flush();
	int a;
	cin>>a;
	return p[make_pair(x,y)]=a;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	l=1;
	r=n;
	while(l+2<=r)
	{
		int x=ask(l,r);
		int mid=(l+r)>>1;
		if(x<=mid)
		{
			int y=ask(l,mid);
			if(y==x)
				r=mid;
			else
				l=mid+1;
		}
		else
		{
			int y=ask(mid,r);
			if(y==x)
				l=mid;
			else
				r=mid-1;
		}
	}
	if(l==r)
		cout<<"! "<<l<<endl;
	else
		cout<<"! "<<l+r-ask(l,r)<<endl;
	return 0;
}