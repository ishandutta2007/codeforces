#include <stdio.h>
#include <string.h>
inline int read()
{
	char c=getchar();int num=0;
	while(c<48||c>57)c=getchar();
	while(c>=48&&c<=57)num=num*10+(c^48),c=getchar();
	return num;
}
int main()
{
	int T=read();
	while(T--)
	{
		long long a=read(),b=read(),c=read(),d=read();
		if(a<=b)printf("%lld\n",b);
		else if(c<=d)puts("-1");
		else printf("%lld\n",b+((a-b-1)/(c-d)+1)*c);
	}
}