#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 400005
#define MAXLOGN 20
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,x;
string s,t;
int dp[MAXN][31];
void upd(int &a,int b) {a=max(a,b);}
string S;
struct SAM{
    vector<map<char,int>> edges; 
    vector<int> link;            
    vector<int> length;
    vector<int> G[MAXM];
    vector<int> sid;
    int st[MAXLOGN+1][2*MAXM];
    int last;                    
    void init(){
        edges.clear(); link.clear(); length.clear(); 
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
    int vs[MAXM*2-1];
	int depth[MAXM*2-1];
	int id[MAXM];
	void dfs(int v,int p,int d,int &k)
	{
		id[v]=k;
		vs[k]=v;
		depth[k++]=d;
		for(int i=0;i<(int)G[v].size();i++)
		{
		    if(G[v][i]!=p)
		    {
		        dfs(G[v][i],v,d+1,k);
		        vs[k]=v;
		        depth[k++]=d;
		    }
		}
	}
	int getMin(int x, int y)
	{
		return depth[x]<depth[y]?x:y;
	}

	void rmq_init(int n)
	{
		for(int i=1;i<=n;++i) st[0][i]=i;
		for(int i=1;1<<i<n;++i)
		    for(int j=1;j+(1<<i)-1<=n;++j)
		        st[i][j]=getMin(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	}
	void init_lca(int V)
	{
		int k=0;
		dfs(0,-1,0,k);
		rmq_init(V*2-1);
	}
	int query(int l, int r)
	{
		int k=31-__builtin_clz(r-l+1);
		return getMin(st[k][l],st[k][r-(1<<k)+1]);
	}
	int lca(int u,int v)
	{
		if(u==v) return u;
		return vs[query(min(id[u],id[v]),max(id[u],id[v]))];
	}
    void build(string &s){
        init();
        int cur=0;
        sid.push_back(0);
        for(int i=0;i<(int)s.size();i++) {cur=add(cur,s[i]); sid.push_back(cur);}
        for(int i=1;i<(int)edges.size();i++) G[link[i]].push_back(i);
        init_lca((int)edges.size());
    }
    int calc_lcp(int i,int j)
    {
        int x=sid[n+m+1-i],y=sid[n+m+1-(n+1+j)];
        return length[lca(x,y)];
    }
}sam;
int main()
{
    scanf("%d",&n);
    cin>>s;
    scanf("%d",&m);
    cin>>t;
    scanf("%d",&x);
    S=s; S+='#'; S+=t;
    reverse(S.begin(),S.end());
    sam.build(S);
    //for(int i=0;i<=n;i++)
        //for(int j=0;j<=m;j++)
        //    printf("i=%d j=%d lcp=%d\n",i,j,sam.calc_lcp(i,j));
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    bool f=false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            if(dp[i][j]==-1) continue;
            upd(dp[i+1][j],dp[i][j]);
            if(j!=x)
            {
                int len=sam.calc_lcp(i,dp[i][j]);
                if(len>0) upd(dp[i+len][j+1],dp[i][j]+len);
            }
        }
    }
    for(int i=0;i<=x;i++) if(dp[n][i]==m) f=true;
    if(f) puts("YES"); else puts("NO");
    return 0;
}