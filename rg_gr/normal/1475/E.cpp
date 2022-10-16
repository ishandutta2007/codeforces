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
int C[1005][1005];
const int mod=1000000007;
signed main()
{
    for(int i=0;i<=1000;i++)C[i][i]=C[i][0]=1;
    for(int i=1;i<=1000;i++)
        for(int j=1;j<i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    int T=read();
    while(T--)
    {
        int n=read(),k=read();
        memset(a,0,sizeof(int)*(n+3));
        for(int i=0;i<n;i++)a[read()]++;
        int i;
        for(i=1000;i;i--)
        {
            if(a[i]<=k)k-=a[i];
            else break;
        }
        printf("%lld\n",C[a[i]][k]);
    }
}