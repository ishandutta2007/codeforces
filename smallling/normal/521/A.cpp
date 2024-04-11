#include<cstdio>
#include<cstring>

#define mo 1000000007

using namespace std;

char s[100010];
int n,cnt[4];
long long ans[100010][4],f[100010][4],ANS,Ans;

int check(char ch)
{
    if(ch=='A')return 0;
    if(ch=='C')return 1;
    if(ch=='G')return 2;
    if(ch=='T')return 3;
}

int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
        cnt[check(s[i])]++;
    ans[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)
            {
                if(f[i-1][k]+1ll*cnt[j]*n==f[i][j])(ans[i][j]+=ans[i-1][k])%=mo;
                if(f[i-1][k]+1ll*cnt[j]*n>f[i][j])f[i][j]=f[i-1][k]+1ll*cnt[j]*n,ans[i][j]=ans[i-1][k];
            }
    for(int i=0;i<4;i++)
    {
        if(f[n][i]==Ans)(ANS+=ans[n][i])%=mo;
        if(f[n][i]>Ans)Ans=f[n][i],ANS=ans[n][i];
    }
    printf("%I64d",ANS);
}