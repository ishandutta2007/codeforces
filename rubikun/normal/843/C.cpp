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
const int mod=1000000007,MAX=300005,INF=1<<30;

vector<vector<int>> ans;

int N;
vector<int> preG[MAX];
int siz[MAX];
vector<int> center;

void findcenter(int u,int p){
    siz[u]=1;
    bool ok=true;
    
    for(int to:preG[u]){
        if(to==p) continue;
        findcenter(to,u);
        if(siz[to]>N/2) ok=false;
        siz[u]+=siz[to];
    }
    
    if(N-siz[u]>N/2) ok=false;
    
    if(ok) center.push_back(u);
}

vector<int> G[MAX];
int par[MAX];

void make(int u,int p){
    for(int to:preG[u]){
        if(to==p) continue;
        G[u].push_back(to);
        par[to]=u;
        make(to,u);
    }
}

void add(int a,int b,int c){
    ans.push_back({a,b,c});
}

int root,ch;
vector<int> X;

void solve(int u){
    for(int to:G[u]){
        solve(to);
    }
    if(si(X)==0){
        add(root,ch,u);
        X.push_back(u);
    }else{
        add(X.back(),par[X.back()],u);
        X.push_back(u);
    }
}

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;a--;b--;
        preG[a].push_back(b);
        preG[b].push_back(a);
    }
    
    findcenter(0,-1);
    
    if(si(center)==1){
        make(center[0],-1);
    }else{
        make(center[0],center[1]);
        make(center[1],center[0]);
    }
    
    for(int r:center){
        root=r;
        for(int to:G[r]){
            ch=to;
            X.clear();
            solve(to);
            X.insert(X.begin(),r);
            int K=X[si(X)-2];
            for(int t=si(X)-4;t>=0;t--){
                add(X[t],X[t+1],K);
            }
        }
    }
    
    cout<<si(ans)<<"\n";
    for(auto a:ans){
        for(int b:a) cout<<b+1<<" ";
        cout<<"\n";
    }
}