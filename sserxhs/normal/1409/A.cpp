#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t,a,b;
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
		read(a);read(b);
		if (a>b) a-=b; else a=b-a;
		if (a==0) puts("0"); else printf("%d\n",(a-1)/10+1);
	}
}