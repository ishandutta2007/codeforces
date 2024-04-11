#include <stdio.h>
#include <string.h> 
#include <math.h>
#include <algorithm>
#define int long long
inline int read()
{
	int num=0;char c=getchar();int f=1;
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
int w0[2000005],w1[2000005],a[2000005];
inline int re1d()
{
    char c=getchar();
    while((c^48)>1)c=getchar();
    return c&1;
}
const int mod=1000000007;
inline int max(int a,int b){return a<b?b:a;}
signed main()
{
    int T=read();
    w0[1]=1;
    /*for(int i=2;i<=200000;i++)
    {
        int tmp=w0[i-1];
        w0[i]=w0[i-1]+2*w1[i-1];
        w0[i]%=mod;
        w1[i]=tmp;
        if(i==3)a[i]=1;
        else if(i==2)a[i]=0;
        else a[i]=a[i-1]+w1[i-1]-1;
    }*/
    a[3]=a[4]=1,a[5]=3;
    
    for(int i=6;i<=2000000;i++)//a[i]=a[i-1]*2%mod;
    {
        a[i]=a[i-1]*2%mod;
        if(i%6==3||i%6==5)a[i]=(a[i]+1)%mod;
        else if(i%6==4)a[i]=(a[i]+mod-1)%mod;
    }
    while(T--)
    //for(int i=1;i<=100;i++)
    {
        int n=read();
        printf("%lld\n",(a[n]*4)%mod);
    }
    //printf("%lld\n",n+n-ans);
}
// 1 0 0 1 1 1 0 0 0
//             1