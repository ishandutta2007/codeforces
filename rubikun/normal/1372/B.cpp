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
        ll N;cin>>N;
        if(N%2==0) cout<<N/2<<" "<<N/2<<"\n";
        else{
            pair<ll,ll> ma=mp(1LL<<60,-1);
            for(ll i=1;i*i<=N;i++){
                if(N%i==0){
                    ll a=i,b=N-a;
                    ll lcm=a/gcd(a,b)*b;
                    if(a&&b) chmin(ma,mp(lcm,a));
                    
                    a=N/i;
                    b=N-a;
                    lcm=a/gcd(a,b)*b;
                    if(a&&b) chmin(ma,mp(lcm,a));
                }
            }
            
            cout<<ma.se<<" "<<N-ma.se<<"\n";
        }
    }
}