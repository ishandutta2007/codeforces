#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005,INF=1<<30;

struct edge{
    int to;
    int length;
};

int N,C=-1;
vector<edge> G[MAX];

bool centroid[MAX];
int subtree_size[MAX];
int centpar[MAX];
int dat[MAX];
ll ans[MAX];

int compute_subtree_size(int u,int p){
    int c=1;
    for(auto a:G[u]){
        if(a.to==p||centroid[a.to]) continue;
        c+=compute_subtree_size(a.to,u);
    }
    return subtree_size[u]=c;
}

pair<int,int> search_centroid(int u,int p,int t){
    pair<int,int> res={INF,-1};
    int s=1,m=0;
    for(auto a:G[u]){
        if(a.to==p||centroid[a.to]) continue;
        
        res=min(res,search_centroid(a.to,u,t));
        
        m=max(m,subtree_size[a.to]);
        s+=subtree_size[a.to];
    }
    m=max(m,t-s);
    res=min(res,{m,u});
    return res;
}

int freq[1<<20];

void pre(int u,int p,int x,int ad){
    x^=dat[u];
    freq[x]+=ad;
    for(auto a:G[u]){
        if(a.to==p) continue;
        if(centroid[a.to]) continue;
        pre(a.to,u,x,ad);
    }
}

ll solve(int u,int p,int x){
    x^=dat[u];
    ll res=0;
    res+=freq[x];
    for(int i=0;i<20;i++) res+=freq[x^(1<<i)];
    
    for(auto a:G[u]){
        if(a.to==p) continue;
        if(centroid[a.to]) continue;
        res+=solve(a.to,u,x);
    }
    ans[u]+=res;
    //cout<<u<<" "<<res<<endl;
    return res;
}

void solve_subproblem(int u,int p){
    compute_subtree_size(u,-1);
    int s=search_centroid(u,-1,subtree_size[u]).second;
    centroid[s]=1;
    if(C==-1) C=s;
    centpar[s]=p;
    
    freq[dat[s]]++;
    for(auto a:G[s]){
        if(centroid[a.to]) continue;
        pre(a.to,s,dat[s],1);
    }
    
    ll sum=0;
    
    for(auto a:G[s]){
        if(centroid[a.to]) continue;
        
        pre(a.to,s,dat[s],-1);
        
        sum+=solve(a.to,s,0);
        
        pre(a.to,s,dat[s],1);
    }
    
    freq[dat[s]]--;
    sum+=freq[0];
    for(int i=0;i<20;i++) sum+=freq[1<<i];
    sum+=2;
    
    for(auto a:G[s]){
        if(centroid[a.to]) continue;
        pre(a.to,s,dat[s],-1);
    }
    
    for(auto a:G[s]){
        if(centroid[a.to]) continue;
        solve_subproblem(a.to,s);
    }
    
    sum/=2;
    ans[s]+=sum;
    centroid[s]=0;
}

void build(int u){
    memset(centpar,-1,sizeof(centpar));
    solve_subproblem(u,-1);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back({b,1});
        G[b].push_back({a,1});
    }
    
    for(int i=0;i<N;i++){
        char c;cin>>c;
        dat[i]=1<<int(c-'a');
    }
    
    build(0);
    
    for(int i=0;i<N;i++) cout<<ans[i]<<" ";
    cout<<endl;
}