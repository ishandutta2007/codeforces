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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    multiset<pair<ll,ll>> A,B;
    for(int i=0;i<N;i++){
        ll l,r;cin>>l>>r;
        A.insert(mp(l,r));
        B.insert(mp(r,l));
    }
    
    ll ans=N;
    
    while(si(B)){
        auto ma1=A.end(),ma2=B.end();
        ma1--;ma2--;
        auto x=*ma1,y=*ma2;
        if(x.fi==y.se&&x.se==y.fi){
            ans+=max(x.fi,x.se);
            A.erase(ma1);
            B.erase(ma2);
        }else{
            ans+=max(x.fi,y.fi);
            auto nex=mp(y.se,x.se);
            A.erase(ma1);
            B.erase(ma2);
            
            A.erase(A.lower_bound(mp(y.se,y.fi)));
            B.erase(B.lower_bound(mp(x.se,x.fi)));
            
            A.insert(nex);
            B.insert(mp(nex.se,nex.fi));
        }
    }
    
    cout<<ans<<endl;
}