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
const int mod=1000000007,MAX=505,INF=1<<30;
bool dp[MAX][MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    dp[0][0][0]=1;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<=K;j++){
            for(int k=0;k<=K;k++){
                if(dp[i][j][k]==0) continue;
                
                dp[i+1][j][k]=1;
                if(j+A[i]<=K) dp[i+1][j+A[i]][k]=1;
                if(k+A[i]<=K) dp[i+1][j][k+A[i]]=1;
            }
        }
    }
    
    set<int> SE;
    
    for(int j=0;j<=K;j++) if(dp[N][j][K-j]) SE.insert(j);
    
    cout<<si(SE)<<endl;
    for(int a:SE) cout<<a<<" ";
    cout<<endl;
}