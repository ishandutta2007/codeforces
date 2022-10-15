#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int p[MAXN],r[MAXN];
bool used[MAXN];
pair<int,int> a[MAXN];
int n;
int cnt=0;
vector<int> G[MAXN];
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
void dfs(int x)
{
    used[x]=true;
    G[cnt].push_back(x);
    if(same(x,a[x].second)||used[a[x].second]) {cnt++; return;} else {unite(x,a[x].second); dfs(a[x].second);}
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i].first);
        a[i].second=i;
    }
    sort(a,a+n);
    memset(used,false,sizeof(used));
    init(n);
    for(int i=0;i<n;i++)
        if(!used[i]) dfs(i);
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++)
    {
        printf("%d ",G[i].size());
        for(int j=0;j<G[i].size();j++)
            printf("%d ",G[i][j]+1);
        printf("\n");
    }
    return 0;
}