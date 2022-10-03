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
const int mod=1000000007,MAX=4005,INF=1<<30;
bool dp[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> p(2*N),A;
        for(int i=0;i<2*N;i++) cin>>p[i];
        int id=0;
        while(id<2*N){
            int to=id+1;
            while(to<2*N&&p[id]>p[to]) to++;
            A.push_back(to-id);
            id=to;
        }
        
        int M=si(A);
        
        for(int i=0;i<=M;i++) for(int j=0;j<=2*N;j++) dp[i][j]=0;
        dp[0][0]=1;
        
        for(int i=0;i<M;i++){
            for(int j=0;j<=2*N;j++){
                if(dp[i][j]==0) continue;
                
                dp[i+1][j]=1;
                dp[i+1][j+A[i]]=1;
            }
        }
        
        if(dp[M][N]) cout<<"YES\n";
        else cout<<"NO\n";
        
    }
}