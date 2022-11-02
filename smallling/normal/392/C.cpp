#include<cstdio>
#include<cstring>

#define mo 1000000007

using namespace std;

int k,now;
long long n;
int c[50][50],C[110],a[3][110],A[110][110],B[110][110];

int main()
{
    scanf("%I64d%d",&n,&k);
    for(int i=0;i<=k;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mo;
    }
    for(int i=1;i<=k+1;i++)
    {
        now=1;
        for(int j=i;j<=k+1;j++)
        {
            A[j][i]=c[k-i+1][k-j+1];
            A[j+k+1][i]=1ll*c[k-i+1][k-j+1]*now%mo;
            now=now*2%mo;
        }
    }
    for(int i=k+2;i<=2*k+2;i++)A[i-(k+1)][i]=1;
    A[1][2*k+3]=1;
    A[2*k+3][2*k+3]=1;
    now=1;
    for(int i=0;i<=k;i++)
    {
        a[1][i]=now;
        now=now*1;
    }
    now=1;
    for(int i=0;i<=k;i++)
    {
        a[2][i]=2*now%mo;
        now=now*2%mo;
    }
    for(int i=1;i<=k+1;i++)C[k+1-i+1]=a[2][i-1],C[k+1+k+1-i+1]=a[1][i-1];
    C[2*k+3]=a[1][k];
    //C*A^(n-1)
    n--;
    while(n)
    {
        if(n&1)
        {
            //C=C*A
            memset(B,0,sizeof(B));
            for(int i=1;i<=1;i++)
                for(int j=1;j<=2*k+3;j++)
                    for(int l=1;l<=2*k+3;l++)
                        (B[i][j]+=1ll*C[l]*A[l][j]%mo)%=mo;
            for(int i=1;i<=2*k+3;i++)C[i]=B[1][i];
        }
        //A=A*A
        memset(B,0,sizeof(B));
        for(int i=1;i<=2*k+3;i++)
            for(int j=1;j<=2*k+3;j++)
                for(int l=1;l<=2*k+3;l++)
                    (B[i][j]+=1ll*A[i][l]*A[l][j]%mo)%=mo;
        for(int i=1;i<=2*k+3;i++)
            for(int j=1;j<=2*k+3;j++)
                A[i][j]=B[i][j];
        n>>=1;
    }
    printf("%d\n",C[2*k+3]);
}