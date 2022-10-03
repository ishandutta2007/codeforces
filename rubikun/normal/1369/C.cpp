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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,K;cin>>N>>K;
        vector<ll> A(N),B(K);
        for(int i=0;i<N;i++) cin>>A[i];
        for(int i=0;i<K;i++) cin>>B[i];
        sort(all(A));
        sort(all(B));
        
        ll ans=0;
        
        int id=0;
        int x=N-1;
        while(id<K&&B[id]==1){
            ans+=A[x]*2;
            x--;
            id++;
        }
        
        for(int i=id;i<K;i++){
            ans+=A[x];
            x--;
        }
        
        x=0;
        for(int i=K-1;i>=id;i--){
            ans+=A[x];
            x+=B[i]-1;
        }
        
        cout<<ans<<"\n";
        
    }
}