/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=1e5+100;
int t,n,a[N],p[N],sh[N];
inline int lowbit(int x){return x&(-x);}
inline void change(int x,int v){while(x<=n)sh[x]+=v,x+=lowbit(x);}
int query(int x){int ans=0;while(x)ans+=sh[x],x-=lowbit(x);return ans;}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main()
{
	t=read();
	while (t--)
	{
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		bool ok=1;
		for (int i=1;i<=n;i++) sh[i]=0;
		for (int i=1;i<=n;i++)
		{
			bool bl=1;
			for (int j=i;j>=1;j--) if (a[i]%(j+1)){bl=0;p[i]=i-j;break;}
			if (bl)
			{
				ok=0;
				printf("NO\n");
				break;
			}
		}
		for (int i=1;i<=n;i++)
		{
			int now=query(p[i]);
			if (now<p[i])
			{
				printf("NO\n");
				ok=0;
				break;
			}
			change(p[i]+1,1);
		}
		if (ok) printf("YES\n");
	}	
}