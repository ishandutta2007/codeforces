#include <stdio.h>
#define int long long
inline int read()//IAKIOI!!!
{
	int num=0;char c=getchar();
	while(c<48||c>57){c=getchar();}
	while(c>=48&&c<=57)num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return num;
}
signed main()
{
	int x=read(),y=read();
	int i=read();
    printf("%lld\n",((x-1)/i+1)*((y-1)/i+1));
	getchar();
	return 0;
}//HELas