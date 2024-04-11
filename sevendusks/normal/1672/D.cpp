/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=2*1e5+100;
int T,n,a[N],b[N],cnt[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
struct node
{
	int v,cnt;
}A[N];
node B[N];
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		for (int i=1;i<=n;i++) b[i]=read();
		for (int i=1;i<=n;i++) cnt[i]=0;
		int wa=0,wb=0;
		for (int i=1;i<=n;)
		{
			int j=i;
			while (j<=n&&a[i]==a[j]) j++;
			A[++wa]=(node){a[i],j-i};
			i=j;
		}
		for (int i=1;i<=n;)
		{
			int j=i;
			while (j<=n&&b[i]==b[j]) j++;
			B[++wb]=(node){b[i],j-i};
			i=j;
		}
		int pos=1;
		for (int i=1;i<=wa;i++)
		{
			if (A[i].v==B[pos].v)
			{
				if (A[i].cnt+cnt[A[i].v]<B[pos].cnt)
				{
					cnt[A[i].v]+=A[i].cnt;
					continue;
				}
				if (A[i].cnt<B[pos].cnt)
				{
					cnt[A[i].v]-=B[pos].cnt-A[i].cnt;
					A[i].cnt=B[pos].cnt;
				}
				cnt[A[i].v]+=A[i].cnt-B[pos].cnt;pos++;
				continue;
			}
			cnt[A[i].v]+=A[i].cnt;
		}
		if (pos!=wb+1) puts("NO");
		else puts("YES");
	}
}