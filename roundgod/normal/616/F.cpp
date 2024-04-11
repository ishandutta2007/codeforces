#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
int n;
string t[MAXN];
int cost[MAXN];
struct GSAM{
    vector<map<char,int>> edges; 
    vector<int> link;            
    vector<int> length;
    vector<ll> dp;
    vector<bool> vis;
    void init(){
        edges.clear(); link.clear(); length.clear(); 
        edges.push_back(map<char,int>());
        link.push_back(-1);
        length.push_back(0);
    }
    int add(int p,char ch) {
        if(edges[p].find(ch)!=edges[p].end()){
            int q=edges[p][ch];
            if(length[p]+1==length[q]) return q;
            edges.push_back(edges[q]); 
            length.push_back(length[p]+1); 
            int qq=edges.size()-1; 
            while(p>=0&&edges[p][ch]==q){
                edges[p][ch]=qq;
                p=link[p];
            }
            link.push_back(link[q]); link[q]=qq;
            return qq;
        }
        edges.push_back(map<char,int>());
        length.push_back(length[p]+1); link.push_back(0);
        int r=edges.size()-1;
        while(p>=0&&edges[p].find(ch)==edges[p].end()) {
            edges[p][ch]=r;
            p=link[p];
        }
        if(p!=-1) {
            int q=edges[p][ch];
            if(length[p]+1==length[q]) link[r]=q;
            else {
                edges.push_back(edges[q]); 
                length.push_back(length[p]+1);
                link.push_back(link[q]); 
                int qq=edges.size()-1;
                link[q]=qq; link[r]=qq;
                while(p>=0&&edges[p][ch]==q) {
                    edges[p][ch]=qq;
                    p=link[p];
                }
            }
        }
        return r;
    }
    void add_str(string &s){
        int cur=0;
        for(int i=0;i<(int)s.size();i++) cur=add(cur,s[i]);
    }
    void add_cost(string &s,int val)
    {
        int cur=0;
        for(int i=0;i<(int)s.size();i++) cur=edges[cur][s[i]];
        while(cur)
        {
            dp[cur]+=val;
            cur=link[cur];
        }
    }
    void dfs(int v)
    {
        vis[v]=true;
        for(auto p:edges[v])
        {
            if(!vis[p.S]) dfs(p.S);
            dp[v]+=dp[p.S];
        }
    }
    ll go()
    {
        vis.resize(edges.size());
        dfs(0);
        ll ans=0;
        for(int i=1;i<(int)edges.size();i++) ans=max(ans,1LL*dp[i]*length[i]);
        return ans;
    }
}gsam;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>t[i];
    for(int i=0;i<n;i++) cin>>cost[i];
    gsam.init();
    for(int i=0;i<n;i++) gsam.add_str(t[i]);
    gsam.dp.resize(gsam.edges.size());
    for(int i=0;i<n;i++) gsam.add_cost(t[i],cost[i]);
    printf("%lld\n",gsam.go());
    return 0;
}