#include <stdio.h>
#include <string.h> 
#include <queue>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
signed main()
{
	int T=read();
	while(T--)
	{
		int x=read(),y=read(),z=read();
		if(x>y)x^=y^=x^=y;
		if(x>z)x^=z^=x^=z;
		if(y>z)y^=z^=y^=z;
		if(y==z)
		{
			puts("YES");
			printf("%lld %lld %lld\n",x,x,y);
		}
		/*else if(x==y)
		{
			puts("YES");
			printf("%lld %lld %lld\n",x,z,z);
		}*/
		else puts("NO");
	}
}