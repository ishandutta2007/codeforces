#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
vector<int> G[MAXN];
string str;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int ask(int u,int v)
{
    printf("? %d %d\n",u,v);
    fflush(stdout);
    int x;
    scanf("%d",&x);
    return x;
}
void answer(int x)
{
    printf("! %d\n",x);
    fflush(stdout);
    exit(0);
}
bool valid[MAXN];
int deg[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
        deg[u]++; deg[v]++;
    }
    memset(valid,true,sizeof(valid));
    queue<int> que;
    for(int i=1;i<=n;i++) if(deg[i]==1) que.push(i);
    while(que.size()>=2)
    {
        int u=que.front(); que.pop();
        int v=que.front(); que.pop();
        int l=ask(u,v);
        if(l==u) answer(u);
        if(l==v) answer(v);
        valid[u]=valid[v]=false;
        for(auto to:G[u]) 
        {
            deg[to]--;
            if(deg[to]==1) que.push(to);
        }
        for(auto to:G[v])
        {
            deg[to]--;
            if(deg[to]==1) que.push(to);
        }
    }
    for(int i=1;i<=n;i++) if(valid[i]) answer(i);
}