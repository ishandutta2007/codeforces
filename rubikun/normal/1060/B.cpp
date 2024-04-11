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

ll f(ll x){
    ll res=0;
    while(x){
        res+=x%10;
        x/=10;
    }
    return res;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N;cin>>N;
    
    vector<ll> A={0,1,2,3,4,5,6,7,8,9};
    ll t=10;
    while(t<(1LL<<50)){
        for(int i=1;i<=9;i++){
            A.push_back(t*i-1);
        }
        t*=10;
    }
    
    ll ans=0;
    
    for(ll x:A){
        if(x>N) break;
        ll y=N-x;
        
        chmax(ans,f(x)+f(y));
    }
    
    cout<<ans<<endl;
}