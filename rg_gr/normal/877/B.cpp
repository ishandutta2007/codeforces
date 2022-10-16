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
char q[100005];
int a[100005],b[100005],c[100005];
signed main()
{
    scanf("%s",q+1);
    int n=strlen(q+1);
    for(int i=1;i<=n;i++)
    {
        if(q[i]==97)a[i]=a[i-1]+1;
        else a[i]=a[i-1];

        if(q[i]==98)b[i]=max(a[i-1]+1,b[i-1]+1);
        else b[i]=max(a[i-1],b[i-1]);

        if(q[i]==97)c[i]=max(c[i-1],max(b[i-1],a[i-1]))+1;
        else c[i]=max(c[i-1],max(b[i-1],a[i-1]));
    }
    printf("%lld\n",max(c[n],max(b[n],a[n])));
}