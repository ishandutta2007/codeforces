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
        int N;ll u,v;cin>>N>>u>>v;
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        ll ans=1LL<<60;
        
        for(int i=0;i+1<N;i++){
            if(abs(A[i]-A[i+1])>=2) chmin(ans,0LL);
            if(A[i]==A[i+1]){
                chmin(ans,u+v);
                chmin(ans,v+v);
            }
            if(abs(A[i]-A[i+1])==1){
                chmin(ans,u);
                chmin(ans,v);
            }
        }
        
        cout<<ans<<endl;
    }
}