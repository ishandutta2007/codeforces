#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
string str;
string s[11];
int l[11],r[11];
ll ans;
struct GSAM
{
    vector<map<char,int>> edges; 
    vector<int> link;            
    vector<int> length;
    vector<int> cnt[11],num[11];
    vector<bool> vis;
    vector<int> G[MAXN];
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
    void dfs_tree(int v)
    {
        for(auto to:G[v])
        {
            for(int i=0;i<n;i++)
                cnt[i][to]+=cnt[i][v];
            dfs_tree(to);
        }
    }
    void dfs_graph(int v)
    {
        vis[v]=true;
        for(auto p:edges[v])
        {
            if(!vis[p.S]) dfs_graph(p.S);
            for(int i=0;i<=n;i++) cnt[i][v]+=cnt[i][p.S];
        }
        bool f=(cnt[n][v]>0?true:false);
        for(int i=0;i<n;i++)
            if(cnt[i][v]<l[i]||cnt[i][v]>r[i]) f=false; 
        if(f&&v) ans+=length[v]-length[link[v]];
    }
    void prepare()
    {
        for(int i=0;i<=n;i++) 
        {
            cnt[i].resize(edges.size());
            num[i].resize(edges.size());
        }
        vis.resize(edges.size());
        for(int i=0;i<=n;i++)
        {
            int cur=0;
            for(int j=0;j<(int)s[i].size();j++) cur=add(cur,s[i][j]);
            while(cur)
            {
                cnt[i][cur]=1;
                cur=link[cur];
            }
        }
        int cur=0;
        dfs_graph(0);
    }
}gsam;
int main()
{
    cin>>str;
    gsam.init();
    gsam.add_str(str);
    cin>>n;
    s[n]=str;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        cin>>l[i]>>r[i];
        gsam.add_str(s[i]);
    }
    ans=0;
    gsam.prepare();
    printf("%lld\n",ans);
    return 0;
}