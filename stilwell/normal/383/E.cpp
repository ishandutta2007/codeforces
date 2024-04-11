#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,l,ans,tot;
int sum[26];
int dec[26][26];
int dec2[26][26][26];
char s[10];

void dfs(int now)
{
    if(now==m)
    {
        ans^=tot*tot;
        ans^=(tot+sum[now])*(tot+sum[now]);
        return;
    }
    dfs(now+1);
    int i,j;
    tot+=sum[now];
    for(i=now+1;i<=m;++i)
    {
        sum[i]-=dec[now][i];
        for(j=i+1;j<=m;++j)
        dec[i][j]-=dec2[now][i][j];
    }
    dfs(now+1);
    for(i=now+1;i<=m;++i)
    {
        sum[i]+=dec[now][i];
        for(j=i+1;j<=m;++j)
        dec[i][j]+=dec2[now][i][j];
    }
    tot-=sum[now];
}

int main()
{
    scanf("%d",&n);m=24;--m;
    for(;n;--n)
    {
        scanf("%s",s+1);
        
        for(i=1;i<=3;++i)
        for(j=1;j<i;++j)
        if(s[i]==s[j])s[i]=0;
        for(i=1;i<=3;++i)if(s[i])++sum[s[i]-'a'];
        
        for(i=1;i<=3;++i)
        if(s[i])
        for(j=1;j<=3;++j)
        if(s[j]&&s[j]>s[i])
        {
            ++dec[s[i]-'a'][s[j]-'a'];
            for(k=1;k<=3;++k)
            if(s[k]&&s[k]>s[j])
            ++dec2[s[i]-'a'][s[j]-'a'][s[k]-'a'];
        }
    }
    dfs(0);
    printf("%d\n",ans);
}