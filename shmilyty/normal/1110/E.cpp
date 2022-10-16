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
int n,a[100001],b[100001];
vector<int> v1,v2;
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		b[i]=read();
	if(a[1]!=b[1]||a[n]!=b[n])
	{
		puts("No");
		return 0;
	}
	for(int i=1;i<n;i++)
		v1.push_back(a[i]-a[i+1]);
	for(int i=1;i<n;i++)
		v2.push_back(b[i]-b[i+1]);
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	for(int i=0;i<v1.size();i++)
		if(v1[i]!=v2[i])
		{
			puts("No");
			return 0;
		}
	puts("Yes");
	return 0;
}