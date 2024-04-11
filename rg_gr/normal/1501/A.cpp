#include <stdio.h>
#include <string.h> 
#include <queue>
#include <algorithm>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
inline int min(int a,int b){return a<b?a:b;}
int a[200005],b[200005],tm[200005];
signed main()
{
    int T=read();
    while(T--)
    {
        int n=read();
        for(int i=1;i<=n;i++)a[i]=read(),b[i]=read();
        for(int i=1;i<=n;i++)tm[i]=read();
        int curt=0;
        for(int i=1;i<=n;i++)
        {
            curt=curt+a[i]-b[i-1]+tm[i];
            //printf("qwq %lld\n",curt);
            if(i!=n)
            {curt+=(b[i]-a[i]-1)/2+1;
            if(curt<b[i])curt=b[i];}
            tt:;
        }
        printf("%lld\n",curt);
        //puts("");
    }
}