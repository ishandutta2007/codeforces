#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 50005
#define MAXM 100005
#define MAXLOGN 18
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string s,ss;
struct SAM{
    vector<map<char,int> > edges; 
    vector<int> link;            
    vector<int> length;
    vector<int> G[MAXM];
    vector<int> sid;
    int st[MAXLOGN+1][2*MAXM];
    void init(){
        edges.clear(); link.clear(); length.clear(); 
        edges.push_back(map<char,int>());
        link.push_back(-1); sid.clear();
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
    int vs[MAXM*2-1];
	int depth[MAXM*2-1];
	int id[MAXM];
	void dfs(int v,int d,int &k)
	{
		id[v]=k;
		vs[k]=v;
		depth[k++]=d;
		for(int i=0;i<(int)G[v].size();i++)
		{
		    dfs(G[v][i],d+1,k);
		    vs[k]=v;
		    depth[k++]=d;
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
		dfs(0,0,k);
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
        for(int i=0;i<(int)edges.size();i++) G[i].clear();
        for(int i=1;i<(int)edges.size();i++) G[link[i]].push_back(i); 
        init_lca((int)edges.size());
    }
    int calc_lcp(int i,int j)
    {
        int x=sid[n-i],y=sid[n-j];
        return length[lca(x,y)];
    }
}sam1,sam2;
bool check(int l)
{
    for(int i=l-1;i+l<n;i+=l)
    {
        int suf=sam1.calc_lcp(i,i+l);
        if(suf==0) continue;
        int pre=sam2.calc_lcp(n-1-i,n-1-(i+l));
        //printf("i=%d j=%d pre=%d suf=%d\n",i,i+l,pre,suf);
        if(pre+suf-1>=l) return true;
    }
    return false;
}
void solve(int l)
{
    vector<bool> tmp(n,true);
    int last=-INF;
    for(int i=l-1;i+l<n;i+=l)
    {
        int suf=sam1.calc_lcp(i,i+l);
        if(suf==0) continue;
        int pre=sam2.calc_lcp(n-1-i,n-1-(i+l));
        pre=min(min(pre,l),i-last);
        if(pre+suf-1>=l)
        {
            for(int k=i-pre+1+l;k<=i-pre+2*l;k++) tmp[k]=false;
            last=i-pre+l;
        }
    }
    string res="";
    for(int j=0;j<n;j++) if(tmp[j]) res+=s[j];
    swap(res,s);
    ss=s; reverse(ss.begin(),ss.end());
    sam1.build(ss); sam2.build(s);
    n=(int)s.size();
}
int main()
{
    cin>>s;
    ss=s; reverse(ss.begin(),ss.end());
    sam1.build(ss); sam2.build(s);
    n=(int)s.size();
    for(int i=1;i<=(int)s.size()/2;i++)
        if(check(i)) solve(i);
    cout<<s<<endl;
}