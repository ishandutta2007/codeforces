#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string s,t;
struct SAM{
    vector<map<char,int>> edges; 
    vector<int> link;            
    vector<int> length,cnt;
    vector<int> G[2*MAXN];
    int last;                    
    void init(){
        edges.clear(); link.clear(); length.clear(); cnt.clear();
        edges.push_back(map<char,int>());
        link.push_back(-1);
        length.push_back(0);
        last=0;
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
        for(auto to:G[v])
        {
            dfs(to);
            cnt[v]+=cnt[to];
        }
    }
    void build(string &s){
        init();
        int cur=0;
        for(int i=0;i<(int)s.size();i++) 
        {
            cur=add(cur,s[i]);
            cnt.resize(edges.size());
            if(t[i]=='0') cnt[cur]=1;
        }
        for(int i=1;i<(int)edges.size();i++) G[link[i]].push_back(i);
        dfs(0);
    }
}sam;
int main()
{
    scanf("%d",&n);
    cin>>s>>t;
    sam.build(s); 
    ll ans=0;
    int cur=0;
    for(int i=0;i<(int)sam.edges.size();i++)
        ans=max(ans,1LL*sam.length[i]*sam.cnt[i]);
    printf("%lld\n",ans);
    return 0;
}