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
//const ll INF=1LL<<60;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

void nor(ll &x,ll &y){
    ll g=gcd(x,y);
    x/=g;
    y/=g;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    map<ll,set<pair<ll,ll>>> SE;
    map<pair<ll,ll>,ll> cnt,on;
    ll N=0;
    
    while(Q--){
        ll t,x,y;cin>>t>>x>>y;
        
        if(t==1){
            ll r=x*x+y*y;
            for(auto p:SE[r]){
                ll mx=p.fi+x,my=p.se+y;
                nor(mx,my);
                cnt[mp(mx,my)]++;
            }
            SE[r].insert(mp(x,y));
            nor(x,y);
            on[mp(x,y)]++;
            N++;
        }else if(t==2){
            ll r=x*x+y*y;
            SE[r].erase(mp(x,y));
            
            for(auto p:SE[r]){
                ll mx=p.fi+x,my=p.se+y;
                nor(mx,my);
                cnt[mp(mx,my)]--;
            }
            nor(x,y);
            on[mp(x,y)]--;
            N--;
        }else{
            nor(x,y);
            cout<<N-2*cnt[mp(x,y)]-on[mp(x,y)]<<"\n";
        }
    }
}