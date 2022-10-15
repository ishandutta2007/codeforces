#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,p[MAXN];
vector<int> v[MAXN];
int adj[MAXN];
bool vis[MAXN];
int choice[MAXN];
vector<vector<int> > cyc;
void bye()
{
    int x;
    scanf("%d",&x);
    exit(0);
}
int main()
{
    scanf("%d",&n);
    if(n%2==0) 
    {
        printf("First\n"); fflush(stdout);
        for(int i=1;i<=2*n;i++) printf("%d%c",i>n?i-n:i,i==2*n?'\n':' ');
        fflush(stdout);
        bye();
    }
    else
    {
        printf("Second\n"); fflush(stdout);
        for(int i=1;i<=2*n;i++) 
        {
            scanf("%d",&p[i]);
            v[p[i]].push_back(i);
        }
        for(int i=1;i<=n;i++) adj[v[i][0]]=v[i][1],adj[v[i][1]]=v[i][0];
        ll s=0;
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            if(vis[i]) continue;
            vis[i]=true;
            int now=i;
            vector<int> tmp;
            tmp.push_back(p[now]);
            s+=now;
            choice[p[now]]=(now==v[p[now]][0]?0:1);
            now=adj[now];
            while(!vis[now>n?now-n:now])
            {
                vis[now>n?now-n:now]=true;
                now=(now>n?now-n:now+n);
                tmp.push_back(p[now]);
                s+=now;
                choice[p[now]]=(now==v[p[now]][0]?0:1);
                now=adj[now];
            }
            cyc.push_back(tmp);
        }
        if(s%(2*n)!=0)
        {
            assert(s%(2*n)==n);
            for(auto x:cyc)
            {
                if(x.size()&1)
                {
                    for(auto y:x) choice[y]^=1;
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++) printf("%d%c",v[i][choice[i]],i==n?'\n':' ');
    }
    return 0;
}