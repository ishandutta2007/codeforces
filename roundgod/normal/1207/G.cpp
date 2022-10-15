#include<bits/stdc++.h>
#define MAXN 400005
#define MAXC 26
#define F first
#define S second
using namespace std;
int n,m;
int bit[MAXN];
vector<pair<int,char> > tree[MAXN];
vector<int> queries[MAXN];
string t[MAXN];
int state[MAXN],ans[MAXN];
int sum(int i)
{
    int s=0;
    while(i)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=400000)
    {
        bit[i]+=x; 
        i+=i&-i;
    }
}
struct aho_corasick {
    int cnt=0,link[MAXN],ch[MAXN][MAXC],nxt[MAXN][MAXC];
    vector<int> queries[MAXN],G[MAXN];
    int tot,st[MAXN],ed[MAXN];
    int add_string(string &s) {
        int cur=0;
        for(char &c:s){
            if(ch[cur][c-'a']==0) ch[cur][c-'a']=++cnt;
            cur=ch[cur][c-'a'];
        }
        return cur;
    }
    void dfs(int v)
    {
        st[v]=++tot;
        for(auto to:G[v]) dfs(to);
        ed[v]=tot;
    }
    void add_state(int state,int v)
    {
        add(st[state],v);
    }
    int query_state(int state)
    {
        return sum(ed[state])-sum(st[state]-1);
    }
    void BFS() {
        queue<int> q;
        for(q.push(0);!q.empty();q.pop()) {
            int u=q.front();
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
        tot=0;
        dfs(0);
    }
} acs;
void dfs_tree(int v,int st)
{
    for(auto id:queries[v])
        ans[id]=acs.query_state(state[id]);
    for(auto p:tree[v])
    {
        int nxtstate=acs.nxt[st][p.S-'a'];
        acs.add_state(nxtstate,1);
        dfs_tree(p.F,nxtstate);
        acs.add_state(nxtstate,-1);
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int type,last;
        char ch;
        cin>>type;
        if(type==1)
        {
            cin>>ch;
            tree[0].push_back(make_pair(i,ch));
        }
        else
        {
            cin>>last>>ch;
            tree[last].push_back(make_pair(i,ch));
        }
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int id; 
        cin>>id>>t[i];
        state[i]=acs.add_string(t[i]);
        //printf("i=%d state=%d\n",i,state[i]);
        queries[id].push_back(i);
    }
    acs.BFS();
    dfs_tree(0,0);
    for(int i=0;i<m;i++) printf("%d\n",ans[i]);
    return 0;
}