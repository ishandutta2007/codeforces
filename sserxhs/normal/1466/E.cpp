#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
const int N=5e5+2,p=1e9+7;
ll a[N];
int cnt[60],f[N],g[N],mi[60];
int n,c,i,t,m,j,k,ans,la,s;
inline void read(register int &x)
{
	register int c=getchar(),fh=1;
	while ((c<48)||(c>57))
	{
		if (c=='-') {c=getchar();fh=-1;break;}
		c=getchar();
	}
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
	x*=fh;
}
inline void read(register ll &x)
{
	register int c=getchar(),fh=1;
	while ((c<48)||(c>57))
	{
		if (c=='-') {c=getchar();fh=-1;break;}
		c=getchar();
	}
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
	x*=fh;
}
int main()
{
	read(t);
	mi[0]=1;
	for (i=1;i<=59;i++) mi[i]=(mi[i-1]<<1)%p;
	while (t--)
	{
		read(n);
		memset(cnt,0,sizeof(cnt));
		memset(f+1,0,n<<2);
		memset(g+1,0,n<<2);
		for (i=1;i<=n;i++)
		{
			read(a[i]);
			for (j=0;j<=59;j++) if (1ll<<j&a[i]) ++cnt[j];
		}
		for (i=1;i<=n;i++) for (j=0;j<=59;j++) if (1ll<<j&a[i])
		{
			f[i]=(f[i]+(ll)cnt[j]*mi[j])%p;
			g[i]=(g[i]+(ll)n*mi[j])%p;
		}
		else g[i]=(g[i]+(ll)cnt[j]*mi[j])%p;
		ans=0;//for (i=1;i<=n;i++) printf("%d: %d %d\n",i,f[i],g[i]);
		for (i=1;i<=n;i++) ans=(ans+(ll)f[i]*g[i])%p;
		printf("%d\n",ans);
	}
}