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
    
    ll N,M;cin>>N>>M;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    ll ans=0;
    for(ll i=1;i<=N;i++){
        ans+=i*(N+1-i);
    }
    for(ll i=0;i+1<N;i++){
        if(A[i]==A[i+1]){
            ans-=(i+1)*(N-i-1);
        }
    }
    //cout<<ans<<endl;
    while(M--){
        ll a,b;cin>>a>>b;a--;
        if(a&&A[a-1]==A[a]){
            ans+=(a)*(N-a);
        }
        if(a+1<N&&A[a]==A[a+1]){
            ans+=(a+1)*(N-a-1);
        }
        A[a]=b;
        if(a&&A[a-1]==A[a]){
            ans-=(a)*(N-a);
        }
        if(a+1<N&&A[a]==A[a+1]){
            ans-=(a+1)*(N-a-1);
        }
        
        cout<<ans<<"\n";
    }
}