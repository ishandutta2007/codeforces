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
const int mod=998244353,MAX=500005,INF=1<<30;

ll N;
vector<pair<int,int>> G[MAX];

int tin[MAX],tout[MAX];
ll sz[MAX];
int timer=0;

void make(int u,int p){
    tin[u]=timer;timer++;
    sz[u]++;
    
    for(auto to:G[u]){
        if(to.fi==p) continue;
        
        make(to.fi,u);
        
        sz[u]+=sz[to.fi];
    }
    
    tout[u]=timer;timer++;
}

vector<pair<ll,int>> A[MAX];
ll cn[MAX];

ll ans=0;

void solve(int u,int p,int c){
    cn[u]=sz[u];
    vector<ll> B;
    for(auto to:G[u]){
        if(to.fi==p) continue;
        
        solve(to.fi,u,to.se);
        
        while(!A[c].empty()){
            int x=A[c].back().se;
            if(tin[to.fi]<=tin[x]&&tout[x]<=tout[to.fi]){
                cn[u]-=A[c].back().fi;
                B.push_back(cn[x]);
                A[c].pop_back();
            }else{
                break;
            }
        }
    }
    
    for(ll x:B) ans+=cn[u]*x;
    
    A[c].push_back(mp(sz[u],u));
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    for(int i=0;i<N-1;i++){
        int a,b,c;cin>>a>>b>>c;a--;b--;c--;
        G[a].push_back(mp(b,c));
        G[b].push_back(mp(a,c));
    }
    
    make(0,-1);
    
    solve(0,-1,N);
    
    for(int i=0;i<N;i++){
        ll al=N;
        for(auto a:A[i]){
            al-=a.fi;
        }
        for(auto a:A[i]){
            ans+=al*cn[a.se];
        }
        //cout<<ans<<endl;
    }
    
    cout<<ans<<endl;
}