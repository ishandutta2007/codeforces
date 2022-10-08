#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define N 111
vector<pair<int,int> > a[N];
int n,g[N][N];bool v[N];vector<int> q;
void way(int x)
{
    if(v[x])return;v[x]=1,q.push_back(x);
    if(!v[a[x][0].first])way(a[x][0].first);
    if(!v[a[x][1].first])way(a[x][1].first);
}
int main()
{
    scanf("%d",&n);
    for(int i=1,x,y,z;i<=n;i++)
        scanf("%d%d%d",&x,&y,&z),g[y][x]=z,
        a[x].push_back(make_pair(y,0)),
        a[y].push_back(make_pair(x,z));
    way(1),q.push_back(q[0]);
    int S=0,T=0;
    for(int i=1;i<q.size();i++)S+=g[q[i-1]][q[i]],T+=g[q[i]][q[i-1]];
    printf("%d\n",min(S,T));
    return 0;
}