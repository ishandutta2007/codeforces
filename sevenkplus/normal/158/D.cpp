#include<cstdio>
#include<algorithm>
using namespace std;
#define INF 1000000007
#define N 20010
int n,a[N],S=-INF;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    for(int i=3;i<=n;i++)if(n%i==0)
        for(int j=0;j<n/i;j++)
        {
            int T=0;
            for(int k=0;k<i;k++)T+=a[j+n/i*k];
            S=max(S,T);
        }
    printf("%d\n",S);
    return 0;
}