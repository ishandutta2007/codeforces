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
int n,a,b,c,d;
int nxt()
{
	if(a==b||c==d)return 0;
	a=(a+1)%n;
	c=(c+n-1)%n;
	return 1;
}
signed main()
{
	n=read(),a=read()%n,b=read()%n,c=read()%n,d=read()%n;
	do{
		if(a==c)return puts("YES")&0;
	}while(nxt());
	puts("NO");
}