#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt[102];
int n,c,fh,i,t,tot,x;
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
		read(n);memset(cnt,0,sizeof(cnt));tot=-1;
		for (i=1;i<=n;i++) {read(x);++cnt[x];}
		//if (n==1) {printf("%d\n",(cnt[0]==1));continue;}
		for (i=0;i<=101;i++) if (cnt[i]<2)
		{
			if (cnt[i]==0)
			{
				if (~tot) printf("%d\n",tot+i); else printf("%d\n",i<<1);
				break;
			}
			if ((cnt[i]==1)&&(tot==-1)) tot=i;
		}
	}
}