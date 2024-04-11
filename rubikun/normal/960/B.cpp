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
const int mod=998244353,MAX=200005,INF=1<<28;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M,a,b;cin>>N>>a>>b;
    M=a+b;
    
    vector<ll> A(N),B(N);
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<N;i++) cin>>B[i];
    
    priority_queue<ll> PQ;
    for(int i=0;i<N;i++) PQ.push(abs(A[i]-B[i]));
    
    while(M--){
        ll x=PQ.top();PQ.pop();
        PQ.push(abs(x-1));
    }
    
    ll ans=0;
    
    while(!PQ.empty()){
        ll x=PQ.top();PQ.pop();
        ans+=x*x;
    }
    
    cout<<ans<<endl;
}