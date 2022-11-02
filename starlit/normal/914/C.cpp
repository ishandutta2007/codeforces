#include<bits/stdc++.h>
#define N 1005
#define M 1000000007
using namespace std;
int l,k,f[N][2],t[N],ans;
char s[N];
inline int C(int x)
{
    int ret=0;
    while(x)
    ret+=x&1,x>>=1;return ret;
}
int main()
{
    scanf("%s%d",s,&k);
    if(!k)return puts("1"),0;
    l=strlen(s);
    for(int i=0;i<l;i++)
    s[i]-='0';
    f[0][1]=1;
    for(int i=0;i<l;i++)
    for(int j=1000;j>=0;j--)
    {
        if(s[i])
        f[j][0]=((f[j][1]+(j?f[j-1][0]:0))%M+f[j][0])%M,
        f[j][1]=f[j-1][1];
        else f[j][0]=((j?f[j-1][0]:0)+f[j][0])%M;
    }
    //
    for(int i=1;i<=1000;i++)
    {
        if(i>1)
        t[i]=t[C(i)]+1;
        if(t[i]==k-1)
        {
            ans=((ans+f[i][0])%M+f[i][1])%M;
        }
    }
    if(k==1)ans--;
    printf("%d",ans);
}