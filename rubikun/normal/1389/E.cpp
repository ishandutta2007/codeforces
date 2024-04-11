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
ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll m,d,w;cin>>m>>d>>w;
        ll n=min(m,d);
        if(w==1){
            cout<<n*(n-1)/2<<"\n";
        }else if(n==1){
            cout<<0<<"\n";
        }else{
            ll g=gcd(d-1,w);
            w/=g;
            
            ll a=(n-1)%w,b=(n-1)/w;
            a++;
            
            ll ans=0;
            
            ans+=(b+1)*b/2*a;
            ans+=b*(b-1)/2*(w-a);
            
            cout<<ans<<"\n";
        }
    }
}