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
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

ll N,ans;
vector<int> G[MAX];
ll siz[MAX];
int color[MAX];

void DFS(int u,int p){
    siz[u]=1;
    for(int to:G[u]){
        if(to==p) continue;
        color[to]=3-color[u];
        DFS(to,u);
        ans+=siz[to]*(N-siz[to]);
        siz[u]+=siz[to];
    }
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
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    color[0]=1;
    DFS(0,-1);
    
    ll a=0,b=0;
    for(int i=0;i<N;i++){
        if(color[i]==1) a++;
        else b++;
    }
    //cout<<ans<<" "<<a<<" "<<b<<endl;
    
    ans+=a*b;
    cout<<ans/2<<endl;
}