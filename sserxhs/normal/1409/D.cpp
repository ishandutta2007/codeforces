#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll n,j,ans,k;
int t,s,i;
int c,tot;
inline void read(int &x)
{
	c=getchar();
	while ((c<48)||(c>57)) c=getchar();
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
}
inline void read(ll &x)
{
	c=getchar();
	while ((c<48)||(c>57)) c=getchar();
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
}
int main()
{
	read(t);
	while (t--)
	{
		read(n);read(s);tot=0;
		for (i=j=1;j<=n;i++,j*=10) tot+=n/j%10;
		if (tot<=s) {puts("0");continue;}
		for (i=j=1;j<=n;i++,j*=10)
		{
			tot-=n/j%10-(i==1);
			if (tot<=s)
			{
				j*=10;
				printf("%lld\n",ll((n/j+1)*j-n));
				break;
			}
		}
	}
}