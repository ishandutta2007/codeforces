#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1000005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,M;cin>>N>>M;
    vector<int> t(N),g(N);
    for(int i=0;i<N;i++){
        cin>>t[i]>>g[i];
    }
    
    ll dp[(1<<N)][N];
    
    for(int i=0;i<(1<<N);i++){
        for(int j=0;j<N;j++){
            dp[i][j]=0;
        }
    }
    
    for(int i=0;i<N;i++){
        dp[1<<i][i]=1;
    }
    
    for(int bit=0;bit<(1<<N);bit++){
        for(int j=0;j<N;j++){
            if(!(bit&(1<<j))) continue;
            for(int k=0;k<N;k++){
                if(bit&(1<<k)) continue;
                if(g[j]==g[k]) continue;
                dp[bit|(1<<k)][k]+=dp[bit][j];
            }
        }
    }
    
    ll ans=0;
    
    for(int bit=0;bit<(1<<N);bit++){
        for(int j=0;j<N;j++){
            int sum=0;
            for(int k=0;k<N;k++){
                if(bit&(1<<k)) sum+=t[k];
            }
            if(sum==M) ans+=dp[bit][j];
        }
    }
    
    cout<<ans%mod<<endl;
    
}