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
int n,cnt=1,last=1,maxx,a[100003];
pair<int,int> p[100001];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
	{
		if(a[i]>a[i-1]&&a[i]>a[i+1])
			p[cnt].first=i-last+1;
		if(a[i]<a[i-1]&&a[i]<=a[i+1])
		{
			p[cnt].second=i-last-p[cnt].first+2;
			if(p[cnt].second>p[cnt].first)
				swap(p[cnt].first,p[cnt].second);
			cnt++;
			last=i;
		}
	}
	p[cnt].second=n-last-p[cnt].first+2;
	if(p[cnt].second>p[cnt].first)
		swap(p[cnt].first,p[cnt].second);
//	for(int i=1;i<=cnt;i++)
//		cout<<p[i].first<<" "<<p[i].second<<endl;
	for(int i=1;i<=cnt;i++)
		maxx=max(maxx,p[i].first);
	int x=0;
	for(int i=1;i<=n;i++)
		if(p[i].first==maxx)
		{
			if(x)
			{
				puts("0");
				return 0;
			}
			x=i;
		}
	if(p[x].first==p[x].second&&p[x].first%2==1)
		puts("1");
	else
		puts("0");
	return 0;
}