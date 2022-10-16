#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <bitset>
#include <map>
#include <algorithm>
#define int long long
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
int a[100005*2];
signed main()
{
    int n=read();
    int st=read();
    double x=1;
    for(int i=0;i<n+n;i++)
    {
        int y=read();
        double g=y;
        x=x-x/g;
        //if(x<0){puts("-1");return 0;}
    }
    //qwq = (st+qwq)*x
    //qwq * (1-x) = st * (x)
    if(x<1e-12)
    {
        puts("-1");
        return 0;
    }
    double qwq=st/x*(1-x);
    
    printf("%.8lf\n",qwq);
    return 0;
}