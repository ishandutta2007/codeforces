#include<bits/stdc++.h>
#define MAXN 200015
#define MAXC 26
#define MAXQ 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,tot;
string str[MAXN];
int ans[MAXQ];
vector<P> queries[MAXN];
vector<int> G[MAXN];
int st[MAXN],ed[MAXN],state[MAXN];
int bit[2*MAXN+1];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=200005)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
void dfs(int v)
{
    st[v]=++tot; 
    for(auto to:G[v]) dfs(to);
    ed[v]=tot;
}
struct aho_corasick {
    int cnt=0,link[MAXN],ch[MAXN][MAXC],nxt[MAXN][MAXC];
    bool term[MAXN];
    int top[MAXN];
    void add(string &s,int id) {
        int cur=0;
        for(char &c:s) {
            if(ch[cur][c-'a']==0) ch[cur][c-'a']=++cnt;
            cur=ch[cur][c-'a'];
        }
        term[cur]=true;
        state[id]=cur;
    }
    void BFS() {
        queue<int> q;
        for(q.push(0);!q.empty();q.pop()) {
            int u=q.front();
            top[u]=(term[link[u]]?link[u]:top[link[u]]);
            for(int i=0;i<MAXC;i++) {
                if(ch[u][i]>0) {
                    int v=ch[u][i];
                    q.push(v);
                    nxt[u][i]=v;
                    link[v]=nxt[link[u]][i];
                    if (link[v]==v) link[v]=0;
                } 
                else nxt[u][i]=nxt[link[u]][i];
            }
        }
        for(int i=1;i<=cnt;i++) G[link[i]].push_back(i);
    }
} acs;
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) 
    {
        cin>>str[i];
        acs.add(str[i],i);
    }
	for(int i=0;i<q;i++)
    {
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        queries[r].push_back(P(k,i));
        queries[l-1].push_back(P(-k,i));
    }
    acs.BFS();
    dfs(0);
    for(int i=1;i<=n;i++)
    {
        int cur=0;
        for(char &c:str[i])
        {
            cur=acs.ch[cur][c-'a'];
            add(st[cur],1);
        }
        for(auto &p:queries[i])
        {
            int tmp=1;
            if(p.F<0) {tmp=-1; p.F=-p.F;}
            int sta=state[p.F];
            ans[p.S]+=tmp*(sum(ed[sta])-sum(st[sta]-1));
        }
    }
    for(int i=0;i<q;i++) printf("%d\n",ans[i]);
    return 0;
}