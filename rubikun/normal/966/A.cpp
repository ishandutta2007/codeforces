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
const ll INF=1LL<<50;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll H,W,N,M,V;cin>>H>>W>>N>>M>>V;
    vector<ll> A={-INF,INF},B={-INF,INF};
    for(int i=0;i<N;i++){
        ll a;cin>>a;
        A.push_back(a);
    }
    for(int i=0;i<M;i++){
        ll a;cin>>a;
        B.push_back(a);
    }
    
    sort(all(A));
    sort(all(B));
    
    int Q;cin>>Q;
    while(Q--){
        ll h1,w1,h2,w2;cin>>h1>>w1>>h2>>w2;
        ll ans=INF;
        auto it=lower_bound(all(A),w1);
        it--;
        chmin(ans,abs(w1-*it)+abs(h2-h1)+abs(w2-*it));
        it++;
        chmin(ans,abs(w1-*it)+abs(h2-h1)+abs(w2-*it));
        
        it=lower_bound(all(B),w1);
        it--;
        chmin(ans,abs(w1-*it)+(abs(h2-h1)+V-1)/V+abs(w2-*it));
        it++;
        chmin(ans,abs(w1-*it)+(abs(h2-h1)+V-1)/V+abs(w2-*it));
        
        if(h1==h2) chmin(ans,abs(w2-w1));
        
        cout<<ans<<"\n";
    }
}