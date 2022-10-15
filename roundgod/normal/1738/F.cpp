#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,c[MAXN],d[MAXN],ord[MAXN];
bool vis[MAXN];
int ask(int v)
{
    printf("? %d\n",v);
    fflush(stdout);
    int x;
    scanf("%d",&x);
    return x;
}
void answer()
{
    printf("!");
    for(int i=1;i<=n;i++) printf(" %d",c[i]);
    printf("\n");
    fflush(stdout);
}
bool cmp(int x,int y)
{
    return d[x]>d[y];
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&d[i]);
        for(int i=1;i<=n;i++) ord[i]=i;
        sort(ord+1,ord+n+1,cmp);
        vector<int> tmp;
        for(int i=1;i<=n;i++) vis[i]=false;
        int tot=0;
        for(int i=1;i<=n;i++)
        {
            int v=ord[i];
            tmp.clear();
            if(!vis[v])
            {
                vis[v]=true;
                ++tot;
                c[v]=tot;
                tmp.push_back(v);
                for(int j=1;j<=d[v];j++)
                {
                    int u=ask(v);
                    if(vis[u])
                    {
                        for(auto y:tmp) c[y]=c[u]; 
                        tmp.clear();
                        break;
                    }
                    else
                    {
                        c[u]=tot; vis[u]=true;
                        tmp.push_back(u);
                    }
                }
            }
        }
        answer();
    }
    return 0;
}