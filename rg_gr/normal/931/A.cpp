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
signed  main()
{
    int a=read(),b=read();
    if(a>b)a^=b^=a^=b;
    if(b-a==1)return puts("1")&0;
    int i=1,ans=0;
    while(1)
    {
        a++;b--;
        ans+=i+i;
        i++;
        if(a+1==b)
        {
            printf("%lld\n",ans+i);
            return 0;
        }
        else if(a==b)
        {
            printf("%lld\n",ans);
            return 0;
        }
    }
}