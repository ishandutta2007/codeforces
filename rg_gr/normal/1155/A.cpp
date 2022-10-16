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
char a[1000005];
unsigned pre[1000005][26];
signed main()
{
    int n=read();
    scanf("%s",a+1);
    for(int i=1;i<=n;i++)a[i]-=97,a[i]=25-a[i];
    for(int i=2;i<=n+1;i++)
    {
        if(i==n+1)
        {
            puts("NO");
            return 0;
        }
        if(a[i]>a[i-1])break;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(a[i]==j)pre[i][j]=i;
            else pre[i][j]=pre[i-1][j];
        }
    }
    int l=0,r=0;
    for(int i=1;i<26;i++)
    {
        int rpos=pre[n][i];
        if(rpos==0)continue;
        int lpos=0;
        for(int j=0;j<i;j++)lpos=max(lpos,pre[rpos-1][j]);
        if(lpos==0)continue;
        if(l<lpos)l=lpos,r=rpos;
        else if(l==lpos&&r<rpos)r=rpos;
    }
    if(l==0)puts("NO");
    else printf("YES\n%lld %lld\n",l,r);
    return 0;
}
//baabbaaB