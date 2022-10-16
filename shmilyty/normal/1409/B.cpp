#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,x,y,a,b,c,t;
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
		read(a);read(b);read(x);read(y);read(n);
		if (a>b) {swap(a,b);swap(x,y);}
		if (a-n>=x) {printf("%lld\n",(ll)(a-n)*b);continue;}
		printf("%lld\n",min((ll)x*max(b-n+(a-x),y),(ll)max(b-n,y)*max(a-n+min(b-y,n),x)));
	}
}