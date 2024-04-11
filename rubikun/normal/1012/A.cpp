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
//const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> A(2*N);
    for(int i=0;i<2*N;i++) cin>>A[i];
    sort(all(A));
    
    ll ans=1LL<<60;
    
    chmin(ans,(A[N-1]-A[0])*(A[2*N-1]-A[N]));
    for(int i=1;i<N;i++){
        chmin(ans,(A[2*N-1]-A[0])*(A[i+N-1]-A[i]));
    }
    
    cout<<ans<<endl;
}