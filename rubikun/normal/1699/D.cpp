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
const int mod=1000000007,MAX=5005,INF=1<<30;

bool can[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        for(int i=0;i<=N;i++) for(int j=0;j<=N;j++) can[i][j]=false;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
            A[i]--;
        }
        for(int i=0;i<N;i++){
            vector<int> hin(N);
            int ma=0;
            for(int j=i;j<N;j++){
                hin[A[j]]++;
                chmax(ma,hin[A[j]]);
                if(((j-i)&1)&&ma*2<=(j-i+1)) can[i][j+1]=true;
            }
        }
        
        vector<vector<int>> pos(N);
        for(int i=0;i<N;i++){
            pos[A[i]].push_back(i);
        }
        
        int ans=0;
        
        for(int i=0;i<N;i++){
            if(si(pos[i])==0) continue;
            vector<int> use;
            for(int a:pos[i]){
                use.push_back(a);
                use.push_back(a+1);
            }
            use.push_back(0);
            use.push_back(N);
            sort(all(use));
            use.erase(unique(all(use)),use.end());
            vector<int> dp(N+1,-INF);
            dp[0]=0;
            for(int a=0;a<si(use);a++){
                if(use[a]<N&&A[use[a]]==i) chmax(dp[use[a]+1],dp[use[a]]+1);
                for(int b=a+1;b<si(use);b++){
                    if(can[use[a]][use[b]]) chmax(dp[use[b]],dp[use[a]]);
                }
            }
            chmax(ans,dp[N]);
        }
        
        cout<<ans<<"\n";
    }
}