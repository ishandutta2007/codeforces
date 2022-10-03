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

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

ll ask(ll a,ll b){
    cout<<"? "<<a<<" "<<b<<endl;
    ll x;cin>>x;return x;
    //return gcd(x+a,x+b);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    //x=(1LL<<29);
    //cout<<x<<endl;
    while(Q--){
        ll base=0,ans=-1;
        for(int t=0;t<30;t++){
            ll a,b;
            if(base){
                a=base;
                b=a+(1LL<<(t+1));
                //cout<<"? "<<a<<" "<<b<<endl;
                ll x=ask(a,b);//cin>>x;
                
                if(x&((1LL<<(t+1))-1)){
                    base+=(1LL<<t);
                    ans=(1LL<<(t+1))-base;
                }else{
                    x=(1LL<<(t+1));
                    ans=x-a;
                }
            }else{
                if(t==29){
                    ans=(1LL<<29);
                    break;
                }
                a=(1LL<<(t+1));
                b=a+(1LL<<(t+1));
                ll x=ask(a,b);
                
                if(x&((1LL<<(t+1))-1)){
                    base+=(1LL<<t);
                    ans=(1LL<<(t+1))-base;
                }else{
                    x=(1LL<<(t+1));
                    ans=x;
                }
            }
        }
        
        cout<<"! "<<ans<<endl;
    }
}