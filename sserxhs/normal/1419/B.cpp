#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,ans,j;
int n,c,fh,i,t;
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
		scanf("%lld",&x);
		j=2;ans=0;
		while (x>=0)
		{
			++ans;
			x-=j*(j-1)>>1;
			j<<=1;
		}
		printf("%d\n",ans-1);
	}
}