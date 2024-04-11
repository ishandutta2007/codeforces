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
const int mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll a,b;cin>>a>>b;
    if(a<b||((a-b)&1)){
        cout<<0<<"\n";
        return 0;
    }
    ll sam=(a-b)/2;
    if(b&sam){
        cout<<0<<"\n";
        return 0;
    }
    ll k=__builtin_popcountll(b);
    if(sam){
        cout<<(1LL<<k)<<"\n";
    }else{
        cout<<(1LL<<k)-2<<"\n";
    }
    
}