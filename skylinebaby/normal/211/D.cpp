#include<bits/stdc++.h>
using namespace std;
long long a[1234567];
int l[1234567];
int r[1234567];
long long BIT1[1234567];
long long BIT2[1234567];
int lowbit(int x)
{
	return (x & (-x));
}
void add1(int i,long long x)
{
	while(i>0)
	{
		if (i>=1234567) break;
		BIT1[i] += x;
		i+=lowbit (i);
	}
}
long long get1(int i)
{
	long long t = 0;
	while (i>0)
	{
		t+=BIT1[i];
		i-=lowbit(i);
	}
	return t;
}
void add2(int i,long long x)
{
	while(i>0)
	{
		if (i>=1234567) break;
		BIT2[i] += x;
		i+=lowbit (i);
	}
}
long long get2(int i)
{
	long long t = 0;
	while (i>0)
	{
		t+=BIT2[i];
		i-=lowbit(i);
	}
	return t;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++) scanf("%lld",&a[i]);
	a[n] = 0;
	stack<pair<long long,int> > s;
	s.push(make_pair(0,-1));
	for(int i = 0;i<=n;i++)
	{
		while(s.top()>make_pair(a[i],i)) 
		{
			r[s.top().second] = i - s.top().second;
			s.pop();
		}
		l[i] = i - s.top().second;
		s.push(make_pair(a[i],i));	
	}
	//for(int i = 0;i<n;i++) printf("%d %d %d\n",i,l[i],r[i]);
	for(int i = 0;i<n;i++)
	{
		int x = max(l[i],r[i]);
		int y = min(l[i],r[i]);
		add1(x, a[i]*(x+y));
		add1(min(x+y,n+1),-a[i]*(x+y));
		add2(x,-a[i]);
		add2(min(x+y,n+1),a[i]);
		add1(y,a[i]*y);
		add1(x,-a[i]*y);
		add2(1,a[i]);
		add2(y,-a[i]);	
		//for(int j = 1;j<=n;j++) printf("%d %d %lld %lld\n",i,j,get1(j),get2(j));	
	}
	int m;
	scanf("%d",&m);
	for(int i = 0;i<m;i++)
	{
		int x;
		scanf("%d",&x);
		long long ans = get1(x) + get2(x)*x;
		printf("%.9lf\n",ans/(double)(n-x+1));
	}
	return 0;
}