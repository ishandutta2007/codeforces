#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<59;

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
        ll a,b,q;cin>>a>>b>>q;
        if(a>b) swap(a,b);
        int x=a*b/gcd(a,b);
        while(q--){
            ll l,r;cin>>l>>r;
            l--;
            ll ans=0;
            
            ans+=l/x*b+min(l-l/x*x+1,b);
            
            swap(l,r);
            ans*=-1;
            
            ans+=l/x*b+min(l-l/x*x+1,b);
            
            cout<<(l-r)-ans<<" ";
        }
        cout<<"\n";
    }
}