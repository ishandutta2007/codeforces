#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+2;
int a[N];
int n,c,fh,i,ans,anss,t,x,j,sum;
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
		read(n);sum=0;
		for (i=1;i<=n;i++) {read(a[i]);sum+=a[i];}
		if (sum%n) {puts("-1");continue;}
		ans=(n-1)*2;
		for (i=2;i<=n;i++) if (a[i]%i) ++ans;
		printf("%d\n",ans);
		for (i=2;i<=n;i++)
		{
			if (a[i]%i)
			{
				printf("%d %d %d\n",1,i,x=i-a[i]%i);
				a[i]+=x;a[1]-=x;
			}
			printf("%d %d %d\n",i,1,a[i]/i);
			a[1]+=a[i];a[i]=0;
		}
		for (i=2;i<=n;i++) printf("%d %d %d\n",1,i,a[1]/n);
	}
}