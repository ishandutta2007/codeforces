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
const int mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    map<pair<ll,ll>,ll> MA;
    while(Q--){
        int t;cin>>t;
        if(t==1){
            ll a,b,w;cin>>a>>b>>w;
            while(a!=b){
                if(a>b) swap(a,b);
                MA[mp(b/2,b)]+=w;
                b/=2;
            }
        }else{
            ll a,b;cin>>a>>b;
            ll ans=0;
            while(a!=b){
                if(a>b) swap(a,b);
                if(MA.count(mp(b/2,b))) ans+=MA[mp(b/2,b)];
                b/=2;
            }
            cout<<ans<<"\n";
        }
    }
}