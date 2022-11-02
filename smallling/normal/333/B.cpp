#include<cstdio>

#define FOR(n) for(int i=1;i<=n;i++)

using namespace std;

int n,m,a[1010],b[1010],ans,x,y;

int main()
{
    scanf("%d%d",&n,&m);
    FOR(m)scanf("%d%d",&x,&y),a[x]=1,b[y]=1;
    for(int i=2;i<n;i++)ans+=1-a[i]+1-b[i];
    if((n&1)&&(!a[n/2+1]&&!b[n/2+1]))ans--;
    printf("%d",ans);
}