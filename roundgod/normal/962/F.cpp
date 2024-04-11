#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

const int maxn = 200005;

struct Edge   //
{
    int u,v;
    Edge(int uu,int vv)
    {
        u = uu;
        v = vv;
    }
};
stack<Edge> s;

struct edge  //
{
    int v,next;
}edges[maxn];

int n,m;        //
int e,head[maxn];
int pre[maxn];           //
int dfs_clock;           //
int iscut[maxn];         //
int bcc_cnt;             //_
int bccno[maxn];         //_
vector<int> bcc[maxn];   //_
vector<int> ecnt[maxn];
map <P,int> f;

void addedges(int u,int v,int no)  //
{
    if (u>v) swap(u,v);
    f[{u,v}]=no;
    edges[e].v = v;
    edges[e].next = head[u];
    head[u] = e++;
    edges[e].v = u;
    edges[e].next = head[v];
    head[v] = e++;
}

int dfs(int u,int fa)
{
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;
    for(int i=head[u];i!=-1;i=edges[i].next)
    {
        int v = edges[i].v;
        Edge e = (Edge){u,v};
        if(!pre[v])
        {
            s.push(e);
            child++;
            int lowv = dfs(v,u);
            lowu = min(lowu,lowv); //lowu
            if(lowv >= pre[u])     //
            {
                iscut[u] = 1;
                bcc_cnt++;
                bcc[bcc_cnt].clear();
                for(;;)            //bcc
                {
                    Edge x = s.top(); s.pop();
                    ecnt[bcc_cnt].push_back(f[{min(x.u,x.v),max(x.u,x.v)}]);
                    if(bccno[x.u] != bcc_cnt) {bcc[bcc_cnt].push_back(x.u); bccno[x.u] = bcc_cnt;}
                    if(bccno[x.v] != bcc_cnt) {bcc[bcc_cnt].push_back(x.v); bccno[x.v] = bcc_cnt;}
                    if(x.u == u && x.v == v) break;
                }
            }
        }
        else if(pre[v] < pre[u] && v != fa)   //lowu
        {
            s.push(e);
            lowu = min(lowu,pre[v]);
        }
    }
    if(fa < 0 && child == 1) iscut[u] = 0;    //
    return lowu;
}

void init()
{
    memset(pre,0,sizeof(pre));
    memset(iscut,0,sizeof(iscut));
    memset(head,-1,sizeof(head));
    memset(bccno,0,sizeof(bccno));
    e = 0; dfs_clock = 0; bcc_cnt = 0;
}
P E[maxn]; 
int num[MAXN];
vector<int> cnt[maxn];
int main()
{
    int u,v;
    scanf("%d%d",&n,&m);
    init();
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        addedges(u,v,i+1);
    }
    for(int i=1;i<=n;i++)
        if(!pre[i]) dfs(i,-1);
    vector<int> ans;
    for(int i=1;i<=bcc_cnt;i++)
    {
        if (bcc[i].size()==ecnt[i].size())
        {
            for (int j=0;j<ecnt[i].size();j++)
                ans.push_back(ecnt[i][j]);
        }
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d ",ans[i]);
    return 0;
}