#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+2;
ll ans;
int a[N],b[N],d[N];
int n,c,fh,i,t,cnt0,cnt1,cnt2;
inline void read(int &x)
{
	c=getchar();fh=1;
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
	while (t--)
	{
		read(n);cnt0=cnt1=cnt2=0;
		for (i=1;i<=n;i++) read(a[i]);
		for (i=1;i<=n;i++) if (a[i]==0) ++cnt0; else if (a[i]>0) ++cnt1; else ++cnt2;
		//if (n-cnt0<5) {puts("0");continue;}
		if (((cnt1+(cnt2>>1<<1))>=5)&&(cnt1))
		{
			cnt1=cnt2=0;ans=0;
			for (i=1;i<=n;i++) if (a[i]>0) b[++cnt1]=a[i]; else if (a[i]<0) d[++cnt2]=-a[i];
			sort(b+1,b+cnt1+1);sort(d+1,d+cnt2+1);
			if ((cnt1>=5)) ans=(ll)b[cnt1]*b[cnt1-1]*b[cnt1-2]*b[cnt1-3]*b[cnt1-4];
			if ((cnt1>=3)&&(cnt2>=2)) ans=max(ans,(ll)b[cnt1]*b[cnt1-1]*b[cnt1-2]*d[cnt2]*d[cnt2-1]);
			if ((cnt1>=1)&&(cnt2>=4)) ans=max(ans,(ll)b[cnt1]*d[cnt2-2]*d[cnt2-3]*d[cnt2]*d[cnt2-1]);
			printf("%lld\n",ans);
		} else if (cnt0) {puts("0");continue;}
		else
		{
			cnt1=cnt2=0;ans=0;
			for (i=1;i<=n;i++) if (a[i]>0) b[++cnt1]=a[i]; else if (a[i]<0) b[++cnt1]=-a[i];
			sort(b+1,b+cnt1+1);
			printf("-%lld\n",(ll)b[1]*b[2]*b[3]*b[4]*b[5]);
		}
	}
}