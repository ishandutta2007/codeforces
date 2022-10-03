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
const int mod=1000000007,MAX=1005;
const ll INF=1LL<<60;

map<ll,int> MA[63];

int solve(ll used,int rem){
    if(rem==0) return 0;
    if(MA[rem].count(used)) return MA[rem][used];
    set<int> SE;
    for(int i=1;i<=rem;i++){
        if(used&(1LL<<i)) continue;
        SE.insert(solve(used|(1LL<<i),rem-i));
    }
    for(int i=0;;i++){
        if(!SE.count(i)) return MA[rem][used]=i;
    }
    return 0;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    int X=0;
    for(int i=0;i<N;i++){
        int x;cin>>x;
        X^=solve(0LL,x);
    }
    
    if(X) cout<<"NO\n";
    else cout<<"YES\n";
    
    for(int i=1;i<=60;i++){
        solve(0LL,i);
    }
}