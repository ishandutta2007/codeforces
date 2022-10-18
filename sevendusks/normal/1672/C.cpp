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
int T,n,a[N];
inline void ckmin(int &a,int b){a=((a<b)?a:b);}
inline void ckmax(int &a,int b){a=((a>b)?a:b);}
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
		int cnt=0;
		for (int i=1;i<n;i++) if (a[i]==a[i+1]) cnt++;
		if (cnt<=1)
		{
			printf("0\n");
			continue;
		}
		int ans=0,now=inf,lim=n;
		while (lim>=1&&a[lim]!=a[lim+1]) lim--;
		for (int i=2;i<=lim;i++)
		{
			if (i==lim&&a[i]!=a[i+1]) break;
			if (a[i]==a[i-1])
			{
				ans++;
				a[i]=now;a[i+1]=now;now--;
			}
		}
		printf("%d\n",ans);
	}
}