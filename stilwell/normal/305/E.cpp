#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int n,i,j,k,q,ans;
int l[5005],r[5005],sg[5005],mex[5005];
char s[5005];

int main()
{
    scanf("%s",s+1);n=strlen(s+1);
    for(i=1;i<=n;++i)
    if(s[i-1]==s[i+1])
    {
        if(l[i-1])l[i]=l[i-1];
        else l[i]=i;
    }
    for(i=n;i>=1;--i)
    if(s[i-1]==s[i+1])
    {
        if(r[i+1])r[i]=r[i+1];
        else r[i]=i;
    }
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=i;++j)
        {
            k=0;
            if(j>=2)k^=sg[j-2];
            if(j<i)k^=sg[i-j-1];
            mex[k]=i;
        }
        for(j=0;mex[j]==i;++j);
        sg[i]=j;
    }
    for(i=1;i<=n;++i)if(l[i]==i)ans^=sg[r[i]-l[i]+1];
    if(ans)
    {
        printf("First\n");
        for(i=1;i<=n;++i)
        if(l[i]==i)
        {
            q=r[i]-l[i]+1;
            for(j=1;j<=q;++j)
            {
                k=0;
                if(j>=2)k^=sg[j-2];
                if(j<q)k^=sg[q-j-1];
                if(ans^sg[q]^k)continue;
                printf("%d\n",i+j-1);
                return 0;
            }
        }
    }else printf("Second\n");
}