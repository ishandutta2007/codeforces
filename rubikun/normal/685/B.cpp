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

int N;
vector<int> G[MAX];
int siz[MAX],ma[MAX];
vector<int> center[MAX];

void findcenter(int u){
    siz[u]=1;
    
    for(int to:G[u]){
        findcenter(to);
        chmax(ma[u],siz[to]);
        siz[u]+=siz[to];
    }
}

vector<int> path;

void solve(int u){
    
    path.push_back(u);
    
    int left=-1,right=si(path),left2=-1,right2=si(path);
    
    while(right-left>1){
        int mid=(left+right)/2;
        int v=path[mid];
        
        if(siz[v]-siz[u]<=siz[v]/2) right=mid;
        else left=mid;
    }
    
    while(right2-left2>1){
        int mid=(left2+right2)/2;
        int v=path[mid];
        
        if(ma[u]<=siz[v]/2) left2=mid;
        else right2=mid;
    }
    
    //cout<<u<<" "<<right<<" "<<left2<<endl;
    
    for(int i=right;i<=left2;i++){
        if(i<0||i>=si(path)) continue;
        center[path[i]].push_back(u);
    }
    
    for(int to:G[u]){
        solve(to);
    }
    
    path.pop_back();
    
    //if(si(G[u])==0) center[u].push_back(u);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,Q;cin>>N>>Q;
    for(int i=1;i<N;i++){
        int p;cin>>p;
        p--;
        G[p].push_back(i);
    }
    
    findcenter(0);
    
    solve(0);
    
    while(Q--){
        int a;cin>>a;
        a--;
        cout<<center[a][0]+1<<"\n";
    }
}