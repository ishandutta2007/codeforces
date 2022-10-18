/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=1e6+100;
int T,n,c,a[N],sum[N],vi[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();c=read();
		for (int i=1;i<=n;i++) a[i]=read();
		sort(a+1,a+1+n);n=unique(a+1,a+1+n)-a-1;
		for (int i=1;i<=c;i++) sum[i]=vi[i]=0;
		for (int i=1;i<=n;i++) sum[a[i]]=vi[a[i]]=1;
		for (int i=1;i<=c;i++) sum[i]+=sum[i-1];
		bool bl=1;
		for (int i=1;i<=n;i++)
		{
			for (int j=a[i];j<=c;j+=a[i])
			{
				int l=j,r=min(c,j+a[i]-1);
				if (sum[r]-sum[l-1]>0&&!vi[j/a[i]]) bl=0;
			}
		}
		if (bl) puts("Yes");
		else puts("No");
	}
}