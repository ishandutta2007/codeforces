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
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<vector<ll>> A(2*N,vector<ll>(2*N));
        ll ans=0;
        ll mi=1LL<<60;
        for(int i=0;i<2*N;i++){
            for(int j=0;j<2*N;j++){
                cin>>A[i][j];
                if(i>=N&&j>=N) ans+=A[i][j];
                if(j==N||j==2*N-1){
                    if(i==0||i==N-1) chmin(mi,A[i][j]);
                }
                if(j==0||j==N-1){
                    if(i==N||i==2*N-1) chmin(mi,A[i][j]);
                }
            }
        }
        
        cout<<ans+mi<<"\n";
    }
}