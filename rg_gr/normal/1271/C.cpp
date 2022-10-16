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
inline int max(int a,int b)
{
    return a<b?b:a;
}
signed main()
{
    int n=read(),sx=read(),sy=read();
    int L=0,R=0,U=0,D=0;
    for(int i=0;i<n;i++)
    {
        int x=read(),y=read();
        if(x>sx)R++;
        if(x<sx)L++;
        if(y>sy)U++;
        if(y<sy)D++;
    }
    int M=max(max(R,U),max(L,D));
    printf("%lld\n",M);
    int x=sx,y=sy;
    if(M==L)printf("%lld %lld\n",x-1,y);
    else if(M==R)printf("%lld %lld\n",x+1,y);
    else if(M==U)printf("%lld %lld\n",x,y+1);
    else printf("%lld %lld\n",x,y-1);
}