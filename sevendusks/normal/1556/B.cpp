/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define m_k make_pair
#define int long long
#define len(a) (int)a.size()
using namespace std;
const int N=1e5+100;
int t,n,a[N],b[N],sh[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
inline int lowbit(int x){return x&(-x);}
inline void change(int x,int v){while(x<=n)sh[x]+=v,x+=lowbit(x);}
inline int query(int x){int ans=0;while(x)ans+=sh[x],x-=lowbit(x);return ans;}
int cal()
{
	for (int i=1;i<=n;i++) sh[i]=0;
	int ans=0;
	for (int i=n;i>=1;i--) ans+=query(b[i]),change(b[i],1);
	return ans;
}
signed main()
{
	t=read();
	while (t--)
	{
		n=read();
		for (int i=1;i<=n;i++) a[i]=(read()&1);
		int x=0,y=0;
		for (int i=1;i<=n;i++)
		{
			if (a[i]) x++;
			else y++;
		}
		if (max(x,y)!=(n+1)/2||min(x,y)!=n/2)
		{
			printf("-1\n");
			continue;
		}
		if (n&1)
		{
			if (y>x)
			{
				swap(x,y);
				for (int i=1;i<=n;i++) a[i]^=1;
			}
			x=1,y=2;
			for (int i=1;i<=n;i++)
			{
				if (a[i]) b[i]=x,x+=2;
				else b[i]=y,y+=2;
			}
			printf("%lld\n",cal());
			continue;
		}
		int MIN=inf;
		x=1,y=2;
		for (int i=1;i<=n;i++)
		{
			if (a[i]) b[i]=x,x+=2;
			else b[i]=y,y+=2;
		}
		MIN=min(MIN,cal());
		x=2,y=1;
		for (int i=1;i<=n;i++)
		{
			if (a[i]) b[i]=x,x+=2;
			else b[i]=y,y+=2;
		}
		MIN=min(MIN,cal());
		printf("%lld\n",MIN);
	}
}