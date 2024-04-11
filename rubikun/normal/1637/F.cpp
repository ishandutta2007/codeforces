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
const int mod=998244353,MAX=200005;
const ll INF=1LL<<60;
vector<int> G[MAX];

ll ans=INF;
ll ma[MAX],sum[MAX],h[MAX];

void pre(int u,int p){
    for(int to:G[u]){
        if(to==p) continue;
        pre(to,u);
        sum[u]+=sum[to];
        chmax(ma[u],ma[to]);
    }
    if(ma[u]<h[u]){
        sum[u]+=h[u]-ma[u];
        ma[u]=h[u];
    }
}

void solve(int u,int p){
    
    ma[u]=0;sum[u]=0;
    for(int to:G[u]){
        //if(to==p) continue;
        sum[u]+=sum[to];
        chmax(ma[u],ma[to]);
    }
    if(ma[u]<h[u]){
        sum[u]+=h[u]-ma[u];
        ma[u]=h[u];
    }
    
    //cout<<u<<endl;
    //for(int i=0;i<5;i++) cout<<ma[i]<<" "<<sum[i]<<endl;
    
    chmin(ans,sum[u]);
    
    vector<ll> marec,sumrec;
    vector<ll> lma,rma;
    ll presum=0,prema=0;
    for(int to:G[u]){
        //if(to==p) continue;
        marec.push_back(ma[to]);
        sumrec.push_back(sum[to]);
        chmax(prema,ma[to]);
        presum+=sum[to];
    }
    
    lma=marec;rma=marec;
    for(int i=1;i<si(lma);i++) chmax(lma[i],lma[i-1]);
    for(int i=si(rma)-2;i>=0;i--) chmax(rma[i],rma[i+1]);
    
    ll save=presum;
    
    int idx=0;
    for(int to:G[u]){
        if(to==p){
            idx++;
            continue;
        }
        
        presum=save;
        
        ll a=ma[u],b=sum[u];
        ll c=ma[to],d=sum[to];
        
        presum-=sum[to];
        ll mama=0;
        if(idx) chmax(mama,lma[idx-1]);
        if(idx+1<si(rma)) chmax(mama,rma[idx+1]);
        
        if(mama<h[u]){
            presum+=h[u]-mama;
            ma[u]=h[u];
        }else{
            ma[u]=mama;
        }
        sum[u]=presum;
        
        solve(to,u);
        
        ma[u]=a;sum[u]=b;
        ma[to]=c;sum[to]=d;
        
        idx++;
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    ll hih=0;
    for(int i=0;i<N;i++){
        cin>>h[i];
        chmax(hih,h[i]);
    }
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    pre(0,-1);
    chmin(ans,sum[0]);
    
    solve(0,-1);
    
    cout<<ans+hih<<"\n";
}