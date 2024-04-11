/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define int long long
#define len(a) (int)a.size()
using namespace std;
int t,n,m,a[50],b[50];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
bool check(int mid)
{
	for (int i=31;i>=0;i--)
	{
		a[i]=((n>>i)&1);
		b[i]=((mid>>i)&1);
	}
	int cnt=0;
	for (int i=31;i>=0;i--) if (b[i])
	{
		int x=0;
		for (int j=31;j>i;j--) if (a[j]!=b[j]) x|=(1ll<<j);
		if (a[i]!=0) x|=(1ll<<i);
		for (int j=0;j<i;j++) x|=(1ll<<j);
		if (x>m) return 0;
	}
	return 1;
}
signed main()
{
	t=read();
	while (t--)
	{
		n=read();m=read();
		if (m<n)
		{
			printf("0\n");
			continue;
		}
		int l=0,r=inf;
		while (l<r)
		{
			int mid=l+((r-l+1)>>1);
			if (check(mid)) l=mid;
			else r=mid-1;
		}
		printf("%lld\n",l);
	}
}