#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=2015,INF=1<<29;
bool dp[MAX][MAX];
int need[MAX][13];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    vector<string> S(N),T={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    for(int i=0;i<N;i++) cin>>S[i];
    
    reverse(all(S));
    
    for(int i=0;i<=N;i++) for(int j=0;j<=10;j++) need[i][j]=INF;
    
    for(int i=0;i<N;i++){
        for(int bit=0;bit<(1<<7);bit++){
            for(int k=0;k<7;k++){
                if(bit&(1<<k)) S[i][k]++;
            }
            for(int l=0;l<10;l++) if(S[i]==T[l]) need[i][l]=__builtin_popcount(bit);
            
            for(int k=0;k<7;k++){
                if(bit&(1<<k)) S[i][k]--;
            }
        }
    }
    
    dp[0][0]=1;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<=K;j++){
            if(!dp[i][j]) continue;
            for(int k=0;k<10;k++){
                if(need[i][k]==INF) continue;
                dp[i+1][j+need[i][k]]=1;
            }
        }
    }
    
    if(dp[N][K]==0){
        cout<<-1<<endl;
        return 0;
    }
    
    int nowa=N,nowb=K;
    
    string ans;
    
    while(nowa){
        for(int k=9;k>=0;k--){
            if(need[nowa-1][k]==INF) continue;
            if(nowb-need[nowa-1][k]>=0&&dp[nowa-1][nowb-need[nowa-1][k]]){
                ans+=char('0'+k);
                nowb=nowb-need[nowa-1][k];
                nowa--;
                break;
            }
        }
    }
    
    cout<<ans<<endl;
}