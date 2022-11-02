#include<cstdio>
#include<algorithm>

#define mo 1000000007

using namespace std;

int n,k,d,f[311][311],ans;

int main()
{
    scanf("%d%d%d",&n,&k,&d);
    f[0][0]=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<=k;j++)
            for(int l=1;l<=k;l++)
                f[i+l][max(j,l)]=(f[i+l][max(j,l)]+f[i][j])%mo;
    for(int i=d;i<=k;i++)
        ans=(ans+f[n][i])%mo;
    printf("%d",ans);   
}