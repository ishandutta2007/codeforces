/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=1e5+100,M=5*1e5+100;
int T,n,a[N],w,ok[N],cnt,t[M];
pair<int,int> b[N];
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
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		for (int i=1;i<=n;i++) a[i]=a[i+1]-a[i];
		if (n==2)
		{
			printf("%d\n",a[1]);
			continue;
		}
		sort(a+1,a+n);
		w=0;
		for (int i=1;i<n;)
		{
			int j=i;
			while (j<n&&a[i]==a[j]) j++;
			b[++w]=m_k(a[i],j-i);
			i=j;
		}
		for (int i=1;i<n-1;i++)
		{
			int z=0;
			for (int j=1;j<=w;j++) z+=b[j].second-1;
			cnt=0;
			for (int j=1;j<w;j++)
			{
				int now=b[j+1].first-b[j].first;
				if (!t[now]) ok[++cnt]=now;
				t[now]++;
			}
			sort(ok+1,ok+1+cnt);
			w=0;
			if (z) b[++w]=m_k(0,z);
			for (int j=1;j<=cnt;j++) b[++w]=m_k(ok[j],t[ok[j]]),t[ok[j]]=0;
		}
		printf("%d\n",b[1].first);
	}
}