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
int n,a[200001];
map<int,pair<int,int> > mp;
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<n;i++)
		for(int l=i+1;l<=n;l++)
		{
			int sum=a[i]+a[l];
			int f=mp[sum].first,s=mp[sum].second;
			if(f&&s)
				if(i!=f&&l!=f&&i!=s&&l!=s)
				{
					puts("YES");
					cout<<i<<" "<<l<<" "<<f<<" "<<s<<endl;
					return 0;
				}
			mp[sum]=make_pair(i,l);
		}
	puts("NO");
	return 0;
}