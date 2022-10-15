#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,tot;
int trans[200][200];
vector<int> perm[200];
vector<int> v;
map<vector<int>,int> id;
int nxt[MAXN][125];
int val[MAXN];
vector<int> cur;
int curans;
bool vis[125];
vector<int> go(vector<int> &a,vector<int> &b)
{
    vector<int> c(k);
    for(int i=0;i<k;i++) c[i]=a[b[i]-1];
    return c;
}
void update(int val)
{
    if(vis[val]) return;
    queue<int> que;
    vis[val]=true; curans++;
    while(que.size()) que.pop();
    cur.push_back(val);
    for(auto u:cur) que.push(u);
    while(que.size())
    {
        int u=que.front(); que.pop();
        for(auto x:cur)
        {
            int to=trans[u][x];
            if(!vis[to])
            {
                cur.push_back(to);
                que.push(to);
                vis[to]=true;
                curans++;
            };
        }
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    v.clear();
    for(int i=1;i<=k;i++) v.push_back(i);
    tot=0;
    do
    {
        perm[++tot]=v;
        id[v]=tot;
    }while(next_permutation(v.begin(),v.end()));
    for(int i=1;i<=tot;i++)
        for(int j=1;j<=tot;j++)
        {
            vector<int> tmp=go(perm[i],perm[j]);
            trans[i][j]=id[tmp];
        }
    for(int i=1;i<=n;i++)
    {
        vector<int> v; v.clear();
        for(int j=0;j<k;j++)
        {
            int x; scanf("%d",&x);
            v.push_back(x);
        }
        val[i]=id[v];
    }
    for(int i=1;i<=tot;i++) nxt[n+1][i]=n+1;
    for(int i=n;i>=0;i--)
    {
        for(int j=1;j<=tot;j++) nxt[i][j]=nxt[i+1][j];
        nxt[i][val[i]]=i;
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        memset(vis,false,sizeof(vis));
        curans=1;
        vis[1]=true;
        cur.clear(); cur.push_back(1);
        int now=i;
        update(val[i]);
        while(now<=n)
        {
            int to=n+1,u=-1;
            for(int j=1;j<=tot;j++)
            {
                if(vis[j]) continue;
                if(nxt[now][j]<to)
                {
                    to=nxt[now][j];
                    u=j;
                }
            }
            if(to==n+1) {ans+=1LL*(n-now+1)*curans; break;}
            ans+=1LL*(to-now)*curans;
            update(u);
            now=to;
        }
    }
    printf("%lld\n",ans);
    return 0;
}