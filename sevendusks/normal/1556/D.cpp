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
const int N=1e5+100;
int n,k,a[N],b[N],c[N];
int A[N],O[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
int AND(int i,int j)
{
	printf("and %lld %lld\n",i,j);
	fflush(stdout);
	return read();
}
int OR(int i,int j)
{
	printf("or %lld %lld\n",i,j);
	fflush(stdout);
	return read();
}
signed main()
{
	n=read();k=read();
	for (int i=2;i<=n;i++)
	{
		A[i]=AND(1,i);
		O[i]=OR(1,i);
	}
	int x=AND(n-1,n);
	for (int i=31;i>=0;i--)
	{
		for (int j=2;j<=n;j++) b[j]=((A[j]>>i)&1),c[j]=((O[j]>>i)&1);
		int bl=-1;
		for (int j=2;j<=n;j++) 
		{
			if (b[j]&&c[j]) a[1]|=(1ll<<i),bl=1;
			if (!b[j]&&!c[j]) bl=0;
		}
		if (bl==-1)
		{
			if ((x>>i)&1) bl=0;
			else a[1]|=(1ll<<i),bl=1;
		}
		for (int j=2;j<=n;j++)
		{
			if (bl==1)
			{
				if (b[j]) a[j]|=(1ll<<i);
			}
			else if (c[j]) a[j]|=(1ll<<i);
		}
	}
	sort(a+1,a+1+n);
	// for (int i=1;i<=n;i++) printf("%d ",a[i]);
	// printf("\n");
	printf("finish %lld\n",a[k]);
}