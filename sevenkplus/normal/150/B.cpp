#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
#define P 1000000007
#define N 2010
int n,m,k;bool c[N][N],v[N];
void ff(int x)
{
    v[x]=1;
    for(int i=1;i<=n;i++)if(c[i][x]&&!v[i])ff(i);
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n-k+1;i++)
    {
        int le=i,ri=i+k-1;
        while(le<ri)c[le][ri]=c[ri][le]=1,le++,ri--;
    }
    int S=1;
    for(int i=1;i<=n;i++)if(!v[i])ff(i),S=(ll)S*m%P;
    printf("%d\n",S);
    return 0;
}