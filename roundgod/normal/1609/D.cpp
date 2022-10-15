#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,d,p[MAXN],r[MAXN],sz[MAXN];
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        p[i]=i;
        r[i]=0;
        sz[i]=1;
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
    if(r[x]<r[y]) {p[x]=y; sz[y]+=sz[x];}
    else
    {
        p[y]=x;
        sz[x]+=sz[y];
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
    scanf("%d%d",&n,&d);
    init(n);
    multiset<int> s;
    for(int i=1;i<=n;i++) s.insert(-1);
    int num=1;
    for(int i=0;i<d;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(same(x,y)) num++;
        else
        {
            x=find(x); y=find(y);
            s.erase(s.find(-sz[x])); s.erase(s.find(-sz[y]));
            unite(x,y);
            s.insert(-sz[find(x)]);
        }
        int ans=0,tot=0;
        auto it=s.begin();
        while(tot<num)
        {
            ans-=*it;
            tot++; if(tot<num) it++;
        }
        printf("%d\n",ans-1);
    }
    return 0;
}