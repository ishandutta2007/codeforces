#include <string.h> 
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){f=c=='-'?-1:f,c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
int a[200005],b[200005];
signed main()
{
    int T=read();
    while(T--)
    {
        int aa=read(),bb=read(),n=read();
        memset(a,0,sizeof(int)*(aa+3));
        memset(b,0,sizeof(int)*(bb+3));
        for(int i=0;i<n;i++)a[read()]++;
        for(int i=0;i<n;i++)b[read()]++;
        int ans=n*(n-1)/2;
        for(int i=1;i<=aa;i++)ans-=a[i]*(a[i]-1)/2;
        for(int i=1;i<=bb;i++)ans-=b[i]*(b[i]-1)/2;
        //ans+=n;
        printf("%lld\n",ans);
    }
}