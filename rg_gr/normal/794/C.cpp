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
char a[500005],b[500005];
char ans[500005];
signed main()
{
    //int n=read(),ans=0;
    scanf("%s%s",a,b);
    int n=strlen(a);
    std::sort(a,a+n);
    std::sort(b,b+n);
    int cur1l=0,cur2l=n-1;
    int cur1r=(n-1)/2,cur2r=cur1r+1;
    int L=0,R=n-1;
    if(n==1){putchar(a[0]);return 0;}
    for(int i=0;i<n;i++)
    {
        //printf("%lld %lld . %lld %lld\n",cur1l,cur1r,cur2r,cur2l);
        if((i^1)&1)
        {
            if(a[cur1l]<b[cur2l])ans[L++]=(a[cur1l++]);
            else ans[R--]=(a[cur1r--]);
        }
        else
        {
            if(b[cur2l]>a[cur1l])ans[L++]=(b[cur2l--]);
            else ans[R--]=(b[cur2r++]);
        }
        
    }
    printf("%s",ans);
    //printf("%lld\n",ans);
}