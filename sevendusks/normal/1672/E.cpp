/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
int n;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
int query(int x)
{
	printf("? %d\n",x);
	fflush(stdout);
	return read();
}
signed main()
{
	n=read();
	int l=1,r=4000000;
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (query(mid)!=1) l=mid+1;
		else r=mid;
	}
	int s=r,ans=s;
	for (int i=2;i<=n;i++) if (s%i!=0)
	{
		int x=s/i;
		if (query(x)==i){ans=min(ans,x*i);continue;}
		while ((x+1)*i<s)
		{
			x++;
			if (query(x)==i)
			{
				ans=min(ans,x*i);
				break;
			}
		}
	}
	printf("! %d\n",ans);
}