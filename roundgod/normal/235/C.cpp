#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct SAM{
    vector<map<char,int>> edges; 
    vector<int> link;            
    vector<int> length;
    vector<int> cnt;
    vector<bool> vis;
    void init(){
        edges.clear(); link.clear(); length.clear(); 
        edges.push_back(map<char,int>());
        link.push_back(-1);
        length.push_back(0);
    }
    int add(int p,char ch) {
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
    void dfs(int v)
    {
        vis[v]=true;
        for(auto p:edges[v])
        {
            if(!vis[p.S]) dfs(p.S);
            if(v) cnt[v]+=cnt[p.S];
        }
    }
    void build(string &s)
    {
        init();
        int cur=0;
        for(int i=0;i<(int)s.size();i++) 
        {
            cur=add(cur,s[i]);
            cnt.resize(edges.size());
        }
        while(cur)
        {
            cnt[cur]=1;
            cur=link[cur];
        }
        vis.resize(cnt.size());
        dfs(0);
    }
    int query(string t)
    {
        int len=(int)t.size();
        set<int> states;
        string tt=t; tt.pop_back();
        t+=tt; 
        //cout<<t<<endl;
        int cur=0,curl=0;
        for(int i=0;i<len;i++) 
        {
            while(cur&&!edges[cur][t[i]]) {cur=link[cur]; curl=length[cur];}
            cur=edges[cur][t[i]];
            if(cur) curl++;
        }
        //printf("cur=%d l=%d r=%d\n",cur,!cur?0:length[link[cur]]+1,length[cur]);
        if(curl==len) states.insert(cur);
        for(int i=len;i<(int)t.size();i++)
        {
            while(cur&&!edges[cur][t[i]]) {cur=link[cur]; curl=length[cur];}
            cur=edges[cur][t[i]];
            if(cur) curl++;
            while(cur&&length[link[cur]]+1>len) {cur=link[cur]; curl=length[cur];}
            //printf("cur=%d l=%d r=%d\n",cur,!cur?0:length[link[cur]]+1,length[cur]);
            if(curl>=len) states.insert(cur);
        }
        int ans=0;
        for(auto x:states) 
            ans+=cnt[x];
        return ans;
    }
}sam;
int main()
{
    string s; cin>>s; sam.build(s);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        string t;
        cin>>t;
        printf("%d\n",sam.query(t));
    }
    return 0;
}