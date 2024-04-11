#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
vector<int> G[MAXN];
int root,p[MAXN],c[MAXN],dep[MAXN];
bool used[MAXN];
int tot;
void dfs(int v,int d)
{
    dep[v]=d;
    for(auto to:G[v]) dfs(to,d+1);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d%d",&p[i],&c[i]);
        if(!p[i]) root=i; else G[p[i]].push_back(i);
    }
    
    memset(used,false,sizeof(used));
    dfs(root,0);
    for(int i=1;i<=n;i++)
    {
        int id=-1,dd=INF;
        for(int j=1;j<=n;j++)
        {
            if(!used[j]&&c[j]==0&&dep[j]<dd)
            {
                id=j; dd=dep[j];
            }
        }
        if(id==-1)
        {
            puts("NO");
            return 0;
        }
        used[id]=true;
        a[id]=++tot;
        int now=p[id];
        while(now)
        {
            if(!used[now])
            {
                c[now]--;
                if(c[now]<0)
                {
                    puts("NO");
                    return 0;
                }
            } 
            now=p[now];
        }
    }
    puts("YES");
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    return 0;
}