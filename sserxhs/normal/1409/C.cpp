#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,t,x,y,i,j,mx,k;
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
int main()
{
	read(t);
	while (t--)
	{
		read(n);read(x);read(y);mx=1e9;
		for (i=1;i<=y-x;i++) if (((y-x)%i==0)&&(i<n))
		{
			c=(y-x)/i;
			k=x%c;if (k==0) k=c;
			if (max(k+(n-1)*c,y)<mx) 
			{
				mx=max(k+(n-1)*c,y);j=i;
			}
		}
		c=(y-x)/j;
		k=x%c;if (k==0) k=c;
		if (k+(n-1)*c<y) k=y-(n-1)*c;
		for (i=1;i<=n;i++) printf("%d ",k+(i-1)*c);puts("");
	}
}