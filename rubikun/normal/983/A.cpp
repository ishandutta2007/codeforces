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
        ll p,q,b;cin>>p>>q>>b;
        ll g=gcd(p,q);
        p/=g;
        q/=g;
        
        bool ok=false;
        
        while(1){
            ll g=gcd(q,b);
            if(g==1) break;
            while(q%g==0) q/=g;
            
            if(q==1) break;
        }
        if(q==1) ok=true;
        
        if(ok) cout<<"Finite\n";
        else cout<<"Infinite\n";
    }
}