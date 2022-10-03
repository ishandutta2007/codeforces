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
const int mod=998244353,MAX=1<<19,INF=1<<30;

vector<ll> pref[MAX],suff[MAX],ma[MAX];
ll sum[MAX];
int N,M;

void solve(int u,int t){
    if(t==N) return;
    solve(2*u,t+1);
    solve(2*u+1,t+1);
    
    pref[u].resize(1<<(N-t));
    suff[u].resize(1<<(N-t));
    ma[u].resize(1<<(N-t));
    sum[u]=sum[2*u]+sum[2*u+1];
    
    for(int a=0;a<(1<<(N-t-1));a++){
        chmax(pref[u][a],pref[2*u][a]);
        chmax(pref[u][a],sum[2*u]+pref[2*u+1][a]);
        
        chmax(suff[u][a],suff[2*u+1][a]);
        chmax(suff[u][a],sum[2*u+1]+suff[2*u][a]);
        
        chmax(ma[u][a],ma[2*u][a]);
        chmax(ma[u][a],ma[2*u+1][a]);
        chmax(ma[u][a],suff[2*u][a]+pref[2*u+1][a]);
    }
    for(int a=0;a<(1<<(N-t-1));a++){
        chmax(pref[u][a+(1<<(N-t-1))],pref[2*u+1][a]);
        chmax(pref[u][a+(1<<(N-t-1))],sum[2*u+1]+pref[2*u][a]);
        
        chmax(suff[u][a+(1<<(N-t-1))],suff[2*u][a]);
        chmax(suff[u][a+(1<<(N-t-1))],sum[2*u]+suff[2*u+1][a]);
        
        chmax(ma[u][a+(1<<(N-t-1))],ma[2*u][a]);
        chmax(ma[u][a+(1<<(N-t-1))],ma[2*u+1][a]);
        chmax(ma[u][a+(1<<(N-t-1))],suff[2*u+1][a]+pref[2*u][a]);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    M=(1<<N);
    for(int i=0;i<M;i++){
        int x;cin>>x;
        sum[M+i]=x;
        pref[M+i].push_back(max(0,x));
        suff[M+i].push_back(max(0,x));
        ma[M+i].push_back(max(0,x));
    }
    
    solve(1,0);
    
    int X=0;
    
    int Q;cin>>Q;
    
    while(Q--){
        int k;cin>>k;
        X^=(1<<k);
        cout<<ma[1][X]<<"\n";
    }
}