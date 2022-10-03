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
        ll N,K;cin>>N>>K;
        pair<ll,ll> a,b;cin>>a.fi>>a.se>>b.fi>>b.se;
        if(a.se>b.se) swap(a,b);
        
        if(a.fi<=b.fi){
            if(b.fi<=a.se){
                K-=N*(a.se-b.fi);
                if(K<=0){
                    cout<<0<<"\n";
                }else{
                    ll can=(a.se-a.fi)+(b.se-b.fi)-2*(a.se-b.fi);
                    if(can*N>=K){
                        cout<<K<<"\n";
                    }else{
                        K-=can*N;
                        cout<<can*N+K*2<<"\n";
                    }
                }
            }else{
                ll ans=1LL<<60;
                ll need=b.fi-a.se;
                ll can=b.se-a.fi;
                ll x=K/can,y=K%can;
                
                for(ll i=1;i<=N;i++){
                    if(can*i>=K){
                        if(y) chmin(ans,(can+need)*x+need+y);
                        else chmin(ans,(can+need)*x);
                    }else{
                        chmin(ans,(can+need)*i+(K-can*i)*2);
                    }
                }
                
                cout<<ans<<"\n";
            }
        }else{
            K-=N*(a.se-a.fi);
            if(K<=0){
                cout<<0<<"\n";
            }else{
                ll can=(b.se-b.fi)-(a.se-a.fi);
                if(can*N>=K){
                    cout<<K<<"\n";
                }else{
                    K-=can*N;
                    cout<<can*N+K*2<<"\n";
                }
            }
        }
    }
}