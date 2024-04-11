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
inline int getcha()
{
    char c=getchar();
    while(c!='W'&&c!='B')c=getchar();
    return c=='B'?1:0;
}
int a[205];
char buf[1000005];
signed main()
{
    int n=read(),q=0,p=0;
    for(int i=0;i<n;i++)q+=a[i]=getcha();
    if(q%2&&n%2==0)
    {
        puts("-1");
        return 0;
    }
    for(int i=0;i<n-1;i++)
    {
        if(a[i]==1)p++,sprintf(buf,"%s%lld ",buf,i+1),a[i]^=1,a[i+1]^=1;
    }
    if(a[n-1]==1)
    for(int i=0;i<n-1;i+=2)p++,sprintf(buf,"%s%lld ",buf,i+1);
    printf("%lld\n%s",p,buf);
    puts("");
}