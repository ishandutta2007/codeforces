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
const int mod=1000000007,MAX=105;
#define ld long double

const ld INF=1e14;

ld dp[MAX][MAX][MAX*10];
ld rui[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    rui[0]=1.0;
    for(int i=1;i<MAX;i++) rui[i]=rui[i-1]*0.9;
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        ld C,T;cin>>C>>T;
        vector<pair<int,int>> S(N);
        for(int i=0;i<N;i++) cin>>S[i].fi>>S[i].se;
        sort(all(S),[](auto a,auto b){
            return a.fi>b.fi;
        });
        
        for(int i=0;i<=N;i++) for(int j=0;j<=N;j++) for(int k=0;k<=10*N;k++) dp[i][j][k]=INF;
        dp[0][0][0]=0;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<=i;j++){
                for(int k=0;k<=j*10;k++){
                    if(dp[i][j][k]==INF) continue;
                    chmin(dp[i+1][j+1][k+S[i].se],dp[i][j][k]+(ld)(S[i].fi)/rui[j+1]);
                    chmin(dp[i+1][j][k],dp[i][j][k]);
                }
            }
        }
        
        int ans=0;
        
        for(int j=0;j<=N;j++){
            for(int k=0;k<=j*10;k++){
                if(dp[N][j][k]==INF) continue;
                
                ld x=dp[N][j][k];
                
                ld t=(sqrt(C*x)-1)/C;
                chmax(t,0.0l);
                chmin(t,T);
                
                if(t+x/(1.0+C*t)+10.0*j<=T) chmax(ans,k);
            }
        }
        
        cout<<ans<<endl;
    }
}