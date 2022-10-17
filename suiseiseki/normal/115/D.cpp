#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 4005
#define mod 1000003
char S[N];
int n,m,v[N],f[N][N];
int main()
{
    scanf("%s",S+1);
    n=strlen(S+1);
    for(int i=1;i<=n;i++)
    {
        if(S[i]=='+'||S[i]=='-')
        {
            m++;
            if(S[i-1]<'0'||S[i-1]>'9')
                v[m]=1;
        }
        if(S[i]=='*'||S[i]=='/')
        {
            m++;
            if(S[i-1]<'0'||S[i-1]>'9')
            {
                puts("0");
                return 0;
            }
        }
    }
    if(S[n]<'0'||S[n]>'9')
    {
        puts("0");
        return 0;
    }
    f[0][0]=1;
    for(int i=0;i<=2*m;i++)
    {
        for(int j=0;j<=min(m,i);j++)
        {
            int k=i-j;
            if(j<k)continue;
            if(j<m)
                f[i+1][j+1]=(f[i+1][j+1]+f[i][j])%mod;
            if(j>0)
            {
                if(v[k+1])
                    f[i+1][j]=(f[i+1][j]+f[i-1][j-1])%mod;
                else
                    f[i+1][j]=(f[i+1][j]+f[i][j])%mod;
            }
        }
    }
    printf("%d\n",f[2*m][m]);
}