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
const int INF=1<<30;
//const ll INF=1LL<<60;

bool dp[MAX][3];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        memset(dp,0,sizeof(dp));
        int N,K;cin>>N>>K;
        vector<string> S(3);
        for(int i=0;i<3;i++){
            cin>>S[i];
            while(si(S[i])<=4*N) S[i]+='.';
            if(S[i][0]=='s') dp[0][i]=1;
        }
        
        for(int t=0;t<N;t++){
            for(int i=0;i<3;i++){
                if(dp[t][i]==0) continue;
                
                for(int to=0;to<3;to++){
                    if(abs(i-to)>=2) continue;
                    
                    bool ok=true;
                    
                    if(S[i][3*t+1]!='.') ok=false;
                    if(S[to][3*t+1]!='.') ok=false;
                    if(S[to][3*t+2]!='.') ok=false;
                    if(S[to][3*t+3]!='.') ok=false;
                    
                    if(ok) dp[t+1][to]=1;
                }
            }
        }
        
        bool res=false;
        for(int i=0;i<3;i++) res|=dp[N][i];
        
        if(res) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}