#include<cstdio>
#include<algorithm>
using namespace std;
#define P 1000000007
#define N 1000010
int f[N],g[N];
int main()
{
    f[0]=0,g[0]=0;
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
        if(i&1)
            f[i]=(g[i-1]+f[i-1]+1)%P,
            g[i]=g[i-1]%P;
        else
            g[i]=(g[i-1]+f[i-1]+1)%P,
            f[i]=f[i-1]%P;
    printf("%d\n",(f[n]+g[n])%P);
    return 0;
}