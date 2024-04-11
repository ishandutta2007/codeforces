#include <stdio.h>
#include <math.h>
#define int long long
inline int read()
{
	int num = 0,f=1; char c = getchar();
	while (c<48 || c>57){if(c=='-')f=-1;c = getchar();}
	while (c >= 48 && c <= 57)num = (num << 3) + (num << 1) + (c ^ 48), c = getchar();
	return num*f;
}
signed main()
{
    int a=read(),b=read(),c=read(),d=read();
    if(a+c==b+b&&b+d==c+c)printf("%lld\n",d+d-c);
    else if(a*c==b*b&&b*d==c*c&&d*d%c==0)printf("%lld\n",d*d/c);
    else puts("42");
    return 0;
}