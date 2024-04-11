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
const ll INF=1LL<<50;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,K,s,t;cin>>N>>K>>s>>t;
    vector<pair<ll,ll>> E(N);
    for(int i=0;i<N;i++) cin>>E[i].fi>>E[i].se;
    
    sort(all(E));
    
    vector<ll> pos(K);
    for(int i=0;i<K;i++){
        cin>>pos[i];
    }
    pos.push_back(0);
    pos.push_back(s);
    sort(all(pos));
    
    K+=2;
    
    ll left=0,right=INF;
    while(right-left>1){
        ll mid=(left+right)/2;
        
        ll sum=0;
        
        for(int i=1;i<K;i++){
            ll d=pos[i]-pos[i-1];
            ll x,y;
            y=mid-d;
            x=d-y;
            if(y<0) sum=INF;
            if(x<0){
                x=0;
                y=d;
            }
            sum+=2*x+y;
        }
        
        if(sum<=t) right=mid;
        else left=mid;
    }
    
    //cout<<right<<endl;
    
    for(int i=0;i<N;i++){
        if(E[i].se>=right){
            cout<<E[i].fi<<endl;
            return 0;
        }
    }
    
    cout<<-1<<endl;
    
    
}