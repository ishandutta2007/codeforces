#include<bits/stdc++.h>
#define MAXN 300005
#define MAXC 26
using namespace std;
int n,m;
struct aho_corasick 
{
    int cnt=0,kmp[MAXN],top[MAXN],ch[MAXN][MAXC],nxt[MAXN][MAXC];
    int pos[MAXN],val[MAXN];
    bool term[MAXN];
    multiset<int> ms[MAXN]; 
 
    void add(string &s,int num) 
    {
        int cur=0;
        for(char &c:s) 
        {
            if(ch[cur][c-'a']==0) ch[cur][c-'a']=++cnt;
            cur=ch[cur][c-'a'];
        }
        pos[num]=cur;
        term[cur]=true; val[num]=0;
        ms[cur].insert(0);
    }
 
    void BFS() 
    {
        queue<int> q;
        for(q.push(0);!q.empty();q.pop()) 
        {
            int u=q.front();
            if(term[kmp[u]]) top[u]=kmp[u]; else top[u]=top[kmp[u]];
            for(int i=0;i<MAXC;i++) 
            {
                if(ch[u][i]>0) 
                {
                    int v=ch[u][i];
                    q.push(v);
                    nxt[u][i]=v;
                    kmp[v]=nxt[kmp[u]][i];
                    if (kmp[v]==v) kmp[v]=0;
                } 
                else nxt[u][i]=nxt[kmp[u]][i];
            }
        }
    }

    void update(int id,int v)
    {
        int p=pos[id];
        ms[p].erase(ms[p].find(val[id]));
        val[id]=v;
        ms[p].insert(val[id]);
    }
    int query(string &t)
    {
        int cur=0,ans=-1;
        for(auto &c:t)
        {
            cur=nxt[cur][c-'a'];
            int tmp=cur;
            if(term[cur]) ans=max(ans,*(--ms[tmp].end()));
            while(top[tmp])
            {
                tmp=top[tmp];
                assert(ms[tmp].size());
                ans=max(ans,*(--ms[tmp].end()));
            }
        }   
        return ans;
    }
} acs;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        acs.add(s,i);
    }
    acs.BFS();
    for(int i=0;i<m;i++)
    {
        int type,x,y;
        string s;
        scanf("%d",&type);
        if(type==1)
        {
            scanf("%d%d",&x,&y);
            acs.update(x,y);
        }
        else
        {
            cin>>s;
            printf("%d\n",acs.query(s));
        }
    }
    return 0;
}