#include<bits/stdc++.h>
#define MAXLOGN 20
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q;
string s;
int dfn[2*MAXN];
bool cmp(int x,int y)
{
	return dfn[x]<dfn[y];
}
struct SAM{
    vector<map<char,int>> edges; 
    vector<int> link;            
    vector<int> length;
    vector<int> sid;
    vector<int> G[2*MAXN],vt[2*MAXN];
    int parent[MAXLOGN][2*MAXN];
    int tot,depth[2*MAXN],st[2*MAXN];
    int szs[2*MAXN],szt[2*MAXN];
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
	void add_edge(int from,int to)
	{
	    vt[from].push_back(to);
	}
	void dfs(int v,int p,int d)
	{
	    dfn[v]=++tot;
	    parent[0][v]=p;
	    depth[v]=d;
	    for(int i=0;i<(int)G[v].size();i++)
		    if(G[v][i]!=p) dfs(G[v][i],v,d+1);
	}
	void init_vtree(int V)
	{
	    dfs(0,-1,0);
	    for(int k=0;k+1<MAXLOGN;k++)
	    {
		    for(int v=0;v<V;v++)
		    {
		        if(parent[k][v]<0) parent[k+1][v]=-1;
		        else parent[k+1][v]=parent[k][parent[k][v]];
		    }
	    }
	}
	int lca(int u,int v)
	{
	    if(depth[u]>depth[v]) swap(u,v);
	    for(int k=0;k<MAXLOGN;k++)
	    {
		    if((depth[v]-depth[u])>>k&1)
		        v=parent[k][v];
	    }
	    if(u==v) return u;
	    for(int k=MAXLOGN-1;k>=0;k--)
	    {
		    if(parent[k][u]!=parent[k][v])
		    {
		        u=parent[k][u];
		        v=parent[k][v];
		    }
	    }
	    return parent[0][u];
	}
	int build_vtree(vector<int> &a)
	{
	    sort(a.begin(),a.end(),cmp);
	    a.erase(unique(a.begin(),a.end()),a.end());
	    assert(a.size()>0);
	    int t=0;
	    st[t++]=a[0];
	    vector<int> newly;newly.clear();
	    for(int i=1;i<(int)a.size();i++)
	    {
		    if(t==0) {st[t++]=a[i]; continue;}
		    int l=lca(a[i],st[t-1]);
		    while(t>1&&dfn[st[t-2]]>=dfn[l]) add_edge(st[t-2],st[t-1]),t--;
		    if(l!=st[t-1]) {add_edge(l,st[t-1]),st[t-1]=l; newly.push_back(l);}
		    st[t++]=a[i];
	    }
	    while(t>1) add_edge(st[t-2],st[t-1]),t--;
	    for(auto it:newly) a.push_back(it);
	    return st[0];
	}
    void build(string &s){
        init();
        int cur=0;
        for(int i=0;i<(int)s.size();i++) 
        {
            cur=add(cur,s[i]);
            sid.push_back(cur);
        }
        for(int i=1;i<(int)edges.size();i++) {G[link[i]].push_back(i); G[i].push_back(link[i]);}
        init_vtree((int)edges.size());
    }
    ll dfs_solve(int v)
    {
        ll ans=0;
        for(auto to:vt[v])
        {
            ans+=dfs_solve(to);
            ans-=1LL*szs[to]*szt[to]*length[v]; 
            szs[v]+=szs[to]; szt[v]+=szt[to];
        }
        ans+=1LL*szs[v]*szt[v]*length[v];
        return ans;
    }
    ll solve(vector<int> &a,vector<int> &b)
    {
        vector<int> c=a;
        for(auto x:b) c.push_back(x);
        int root=build_vtree(c);
        ll ans=dfs_solve(root);
        for(auto x:c) {szs[x]=szt[x]=0; vt[x].clear();}
        return ans;
    }
}sam;
int main()
{
    scanf("%d%d",&n,&q);
    cin>>s;
    reverse(s.begin(),s.end());
    sam.build(s);
    for(int i=0;i<q;i++)
    {
        vector<int> a,b;
        int x,y; scanf("%d%d",&x,&y);
        while(x--)
        {
            int z; scanf("%d",&z);
            a.push_back(sam.sid[n-z]);
            sam.szs[sam.sid[n-z]]++;
        }
        while(y--)
        {
            int z; scanf("%d",&z);
            b.push_back(sam.sid[n-z]);
            sam.szt[sam.sid[n-z]]++;
        }
        printf("%lld\n",sam.solve(a,b));
    }
    return 0;
}