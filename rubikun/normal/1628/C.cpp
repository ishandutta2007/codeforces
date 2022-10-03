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
const int mod=1000000007,MAX=2005;
const ll INF=1LL<<61;

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<vector<ll>> S(N,vector<ll>(N));
        for(int i=0;i<N;i++) for(int j=0;j<N;j++) cin>>S[i][j];
        if(N==2){
            cout<<(S[0][0]^S[0][1])<<"\n";
            continue;
        }
        vector<vector<ll>> X(N,vector<ll>(N));
        for(int i=1;i<N;i++){
            for(int j=0;j<N;j++){
                X[i][j]=S[i-1][j];
                if(i) S[i-1][j]^=X[i][j];
                if(i+1<N) S[i+1][j]^=X[i][j];
                if(j) S[i][j-1]^=X[i][j];
                if(j+1<N) S[i][j+1]^=X[i][j];
            }
        }
        
        ll ans=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                //cout<<X[i][j]<<" ";
                ans^=X[i][j];
            }
            //cout<<endl;
        }
        
        cout<<ans<<"\n";
    }
}