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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll a,b;cin>>a>>b;
        if(a>b) swap(a,b);
        ll ans=min(a,b-a);
        a-=ans;
        b-=2*ans;
        
        if(a){
            ll p=a/3;
            a-=p*3;
            b-=p*3;
            ans+=p*2;
        }
        
        if(a>=1&&b>=2) ans++;
        
        cout<<ans<<"\n";
    }
}