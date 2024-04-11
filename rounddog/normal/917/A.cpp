#include<bits/stdc++.h>
#define maxn 5020

using namespace std;
int a[maxn],b[maxn],n,ans,r;
bool f[maxn][maxn];
char s[maxn];

int main()
{
    scanf("%s",s); n=strlen(s); a[0]=b[n]=0;
    for (int i=1;i<=n;i++)
    {
        if (s[i-1]=='('||s[i-1]=='?') a[i]=a[i-1]+1; else a[i]=a[i-1]-1;
    }
    for (int i=n-1;i>=0;i--)
        if (s[i]=='(') b[i]=b[i+1]-1; else b[i]=b[i+1]+1;
    memset(f,true,sizeof(f));
    for (int i=0;i<=n;i++)
    {
        r=a[i];
        for (int j=i+1;j<=n;j++)
        {
            r=min(r,a[j]);
            if (r<a[i]) {f[i][j]=false;}
        }
        r=b[i];
        for (int j=i-1;j>=0;j--)
        {
            r=min(r,b[j]);
            if (r<b[i]) {f[j][i]=false;}
        }
    }
    ans=0;
    for (int i=0;i<=n;i++)
        for (int j=i+2;j<=n;j+=2)
            ans+=f[i][j];
    printf("%d\n",ans);
    return 0;
}