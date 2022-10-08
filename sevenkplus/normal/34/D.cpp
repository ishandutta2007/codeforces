#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define pb push_back
#define N 50010
vector<int> a[N];int n,p0,p1,f[N];
void ff(int x)
{
    for(vector<int>::iterator i=a[x].begin();i!=a[x].end();i++)
        if(*i!=f[x])f[*i]=x,ff(*i);
}
int main()
{
    scanf("%d%d%d",&n,&p0,&p1);
    for(int i=1,x;i<=n;i++)if(i!=p0)
        scanf("%d",&x),a[i].pb(x),a[x].pb(i);
    ff(p1);
    for(int i=1,F=1;i<=n;i++)
        if(i!=p1){if(F)F=0;else printf(" ");printf("%d",f[i]);}
    puts("");
    return 0;
}