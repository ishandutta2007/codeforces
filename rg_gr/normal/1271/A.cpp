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
inline int min(int a,int b)
{
    return a>b?b:a;
}
signed main()
{
    int a=read(),d=read(),c=read(),b=read(),e=read(),f=read();

    int A=a,B=b,C=c,D=d,E=e,F=f;
    int anse=0;
    anse+=min(a,b)*e;b-=min(a,b);
    anse+=min(min(b,c),d)*f;
    int ansf=0;
    int u=min(min(B,C),D);
    ansf+=u*f,B-=u;
    ansf+=min(A,B)*e;
    //printf("%lld %lld\n",anse,ansf);
    printf("%lld\n",anse>ansf?anse:ansf);
}