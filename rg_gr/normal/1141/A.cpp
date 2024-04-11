#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <unordered_map>
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
signed main()
{
    int n=read(),m=read();
    if(m%n){puts("-1");return 0;}
    m/=n;
    int c=0;
    while(m%2==0)m/=2,c++;
    while(m%3==0)m/=3,c++;
    if(m==1)printf("%lld\n",c);
    else puts("-1");
}