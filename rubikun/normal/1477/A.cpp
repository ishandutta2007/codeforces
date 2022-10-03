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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;ll K;cin>>N>>K;
        vector<ll> X(N);
        for(int i=0;i<N;i++) cin>>X[i];
        sort(all(X));
        
        ll g=0;
        for(int i=1;i<N;i++){
            g=gcd(g,X[i]-X[i-1]);
        }
        
        ll a=abs(X[0]-K);
        if(a%g==0) cout<<"YES\n";
        else cout<<"NO\n";
    }
}