#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define link dkasod
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,sz;
string s[MAXN];
string t;
struct SAM 
{
    vector<map<char,int>> edges; 
    vector<int> link;            
    vector<int> length,cnt;
    vector<int> G[2*MAXN];
    vector<int> pos;
    int last;                    
    void init()
    {
        for(int i=0;i<=last;i++) G[i].clear();
        edges.clear(); link.clear(); length.clear(); cnt.clear();
    }
    void build(string s) 
    {
        init();
        edges.push_back(map<char,int>());
        link.push_back(-1);
        length.push_back(0);
        last=0;
        for(int i=0;i<s.size();i++) 
        {
            edges.push_back(map<char,int>());
            length.push_back(i+1);
            link.push_back(0);
            int r=edges.size()-1;
            int p=last;
            while(p>=0 && edges[p].find(s[i])==edges[p].end()) 
            {
                edges[p][s[i]]=r;
                p=link[p];
            }
            if(p!=-1) 
            {
                int q=edges[p][s[i]];
                if(length[p]+1==length[q]) link[r]=q;
                else 
                {
                    edges.push_back(edges[q]); 
                    length.push_back(length[p]+1);
                    link.push_back(link[q]); 
                    int qq=edges.size()-1;
                    link[q]=qq; link[r]=qq;
                    while(p>=0&&edges[p][s[i]]==q) 
                    {
                        edges[p][s[i]]=qq;
                        p=link[p];
                    }
                }
            }
            last=r;
        }
        cnt.resize(edges.size()); 
        for(int i=1;i<(int)edges.size();i++) 
            G[link[i]].push_back(i);
    }
    void ins(string &s)
    {
        int now=0;
        for(int i=0;i<(int)s.size();i++)
        {
            if(edges[now].find(s[i])==edges[now].end()) return;
            now=edges[now][s[i]];
        }
        cnt[now]++;
    }
    void dfs(int v)
    {
        for(auto to:G[v]) 
        {
            cnt[to]+=cnt[v];
            dfs(to);
        }
    }
    void solve()
    {
        for(int i=0;i<n;i++) ins(s[i]);
        dfs(0);
        int now=0;
        pos.resize(sz+1);
        for(int i=0;i<=sz;i++)
        {
            pos[i]=cnt[now];
            if(i!=sz) now=edges[now][t[i]];
        }
    }
}sam,rsam;
int main()
{
    cin>>t; sz=(int)t.size();
    scanf("%d",&n);
    for(int i=0;i<n;i++) cin>>s[i];
    sam.build(t); sam.solve();
    reverse(t.begin(),t.end());
    for(int i=0;i<n;i++) reverse(s[i].begin(),s[i].end());
    rsam.build(t); rsam.solve();
    ll ans=0;
    for(int i=1;i<=sz-1;i++) ans+=1LL*sam.pos[i]*rsam.pos[sz-i];
    printf("%lld\n",ans);
    return 0;
}