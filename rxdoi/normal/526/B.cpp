#include <cstdio>
#include <algorithm>

#define rep(i,j,k) for (int (i)=(j);(i)<=(k);++(i))

using namespace std;

typedef long long ll;

const int N=1<<20;

ll ans,maxd,d[N+10],b[N+10];
int n,a[N+10];

void dfs2(int x)
{
    if ((x<<1)<(1<<n+1)) dfs2(x<<1);
    if ((x<<1|1)<(1<<n+1)) dfs2(x<<1|1);
    ans+=abs(b[x<<1]-b[x<<1|1]);
    b[x]=max(b[x<<1],b[x<<1|1])+b[x];
}

int main()
{
    scanf("%d",&n);
    rep(i,2,(1<<n+1)-1) scanf("%d",a+i),b[i]=a[i];
    dfs2(1);
    printf("%I64d\n",ans);
    return 0;
}