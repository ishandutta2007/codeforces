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
const int mod=1000000007,MAX=3005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,K;cin>>N>>K;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    ll ans=0;
    vector<ll> p;
    priority_queue<pair<ll,ll>> PQ;
    
    for(int i=0;i<K;i++) PQ.push({A[i],i});
    
    for(ll i=K;i<K+N;i++){
        if(i<N) PQ.push({A[i],i});
        
        auto a=PQ.top();PQ.pop();
        
        p.push_back(a.se);
        ans+=a.fi*(i-a.se);
    }
    
    cout<<ans<<endl;
    
    vector<ll> res(N);
    
    for(int i=0;i<si(p);i++){
        res[p[i]]=K+1+i;
    }
    
    for(int a:res) cout<<a<<" ";
    cout<<"\n";
}