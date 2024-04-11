#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
string str[MAXN];
vector<int> G[MAXN];
int cnt[MAXN],dp[MAXN];
struct GSAM
{
    vector<map<char,int> > edges; 
    vector<int> link;            
    vector<int> length;
    int last;                    
    void init()
    {
        edges.clear(); link.clear(); length.clear(); 
        edges.push_back(map<char,int>());
        link.push_back(-1);
        length.push_back(0);
    }
    int add(int p,char ch) 
    {
        if(edges[p].find(ch)!=edges[p].end())
        {
            int q=edges[p][ch];
            if(length[p]+1==length[q]) return q;
            edges.push_back(edges[q]); 
            length.push_back(length[p]+1); 
            int qq=edges.size()-1; 
            while(p>=0&&edges[p][ch]==q)
            {
                edges[p][ch]=qq;
                p=link[p];
            }
            link.push_back(link[q]); link[q]=qq;
            return qq;
        }
        edges.push_back(map<char,int>());
        length.push_back(length[p]+1); link.push_back(0);
        int r=edges.size()-1;
        while(p>=0&&edges[p].find(ch)==edges[p].end()) 
        {
            edges[p][ch]=r;
            p=link[p];
        }
        if(p!=-1) 
        {
            int q=edges[p][ch];
            if(length[p]+1==length[q]) link[r]=q;
            else 
            {
                edges.push_back(edges[q]); 
                length.push_back(length[p]+1);
                link.push_back(link[q]); 
                int qq=edges.size()-1;
                link[q]=qq; link[r]=qq;
                while(p>=0&&edges[p][ch]==q) 
                {
                    edges[p][ch]=qq;
                    p=link[p];
                }
            }
        }
        return r;
    }
    void add_str(string &s)
    {
        int cur=0;
        for(int i=0;i<(int)s.size();i++) cur=add(cur,s[i]);
    }
    void build_graph()
    {
        for(int i=1;i<(int)edges.size();i++) G[link[i]].push_back(i);
    }
}gsam;
bool vis[MAXN];
void dfs(int v)
{
    dp[v]+=(cnt[v]>=k?gsam.length[v]-gsam.length[gsam.link[v]]:0);
    for(auto to:G[v])
    {
        dp[to]+=dp[v];
        dfs(to);
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) cin>>str[i];
    gsam.init();
    for(int i=0;i<n;i++) gsam.add_str(str[i]);
    gsam.build_graph();
    for(int i=0;i<n;i++)
    {
        int cur=0;
        vector<int> save;
        for(int j=0;j<(int)str[i].size();j++)
        {
            cur=gsam.edges[cur][str[i][j]];
            int now=cur;
            while(now&&(!vis[now]))
            {
                vis[now]=true;
                cnt[now]++;
                save.push_back(now);
                now=gsam.link[now];
            }
        }
        for(auto x:save) vis[x]=false;
    }
    dfs(0);
    for(int i=0;i<n;i++)
    {
        int cur=0;
        ll ans=0;
        for(int j=0;j<(int)str[i].size();j++)
        {
            cur=gsam.edges[cur][str[i][j]];
            ans+=dp[cur];
        }
        printf("%lld ",ans);
    }
    puts("");
    return 0;
}