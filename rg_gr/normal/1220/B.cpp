#include <stdio.h>
#include <string.h> 
#include <queue>
#include <math.h>
#include <algorithm>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
int a[1005][1005];
inline int sqrtT(int x)
{
    int q=sqrt(x);
    if(q*q==x)return q;
    else return q+1;
}
signed main()
{
    int n=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a[i][j]=read();
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            printf("%lld ",sqrtT(a[1][2]*a[1][3]/a[2][3]));
        }
        else if(i==2)printf("%lld ",sqrtT(a[1][2]*a[2][3]/a[1][3]));
        else printf("%lld ",sqrtT(a[i][1]*a[i][2]/a[1][2]));
    }
}