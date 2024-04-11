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
const int mod=1000000007,MAX=300005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,L,R;cin>>N>>L>>R;
    int s;
    for(int k=60;k>=0;k--){
        if(N&(1LL<<k)){
            s=k;
            break;
        }
    }
    if(N==0){
        cout<<0<<endl;
        return 0;
    }
    L--;
    ll ans=0;
    for(ll i=L;i<R;i++){
        ll M=N,now=i;
        for(int k=s;k>=0;k--){
            //cout<<k<<" "<<M<<" "<<now<<endl;
            if(now==((1LL<<k)-1)){
                if(M&1) ans++;
                break;
            }
            if(now>=(1LL<<k)){
                now-=((1LL<<k));
            }
            M>>=1;
        }
    }
    
    cout<<ans<<endl;
}