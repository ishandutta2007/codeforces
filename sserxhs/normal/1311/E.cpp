#include <bits/stdc++.h>
using namespace std;
const int N=5e3+2;
int f[N],a[N];
int t,n,i,d,ncs,suc,m,p,tp;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&d);suc=0;ncs=1;a[1]=1;tp=p=1;m=0;
		if (n*(n-1)<d*2) {puts("NO");continue;}
		for (i=1;i<=n;i++) f[i]=i-1;d=(n*(n-1)>>1)-d;
		for (i=n;i-1>ncs;i--)
		{
			if (i-1-ncs>=d) {f[i]=(i-1-d);suc=1;break;}
			d-=(i-1-ncs);f[i]=a[++m];//printf("%d:%d %d\n",i,f[i],ncs);
			a[++p]=i;a[++p]=i;++tp;
			if ((tp+2&tp+1)==0)
			{
				a[++p]=(++ncs);++tp;
			}
		}
		if ((!suc)&&(i-1-ncs>=d)&&(d)) {f[i]=(i-1-d);suc=1;}
		if (suc)
		{
			puts("YES");for (i=2;i<=n;i++) printf("%d ",f[i]);puts("");
		} else puts("NO");
	}
}