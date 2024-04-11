#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005;
const ll INF=1LL<<60;

ll dp[MAX][1<<7],dp2[MAX][1<<7],sum[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,P,K;cin>>N>>P>>K;
    vector<pair<ll,vector<ll>>> A(N);
    for(int i=0;i<N;i++) cin>>A[i].first;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<P;j++){
            ll a;cin>>a;
            A[i].second.push_back(a);
        }
    }
    sort(all(A));
    
    for(int i=0;i<=N;i++){
        for(int j=0;j<1<<P;j++){
            dp[i][j]=-INF;
        }
    }
    dp[0][0]=0;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<1<<P;j++){
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            for(int k=0;k<P;k++){
                if(j&(1<<k)) continue;
                dp[i+1][j|(1<<k)]=max(dp[i+1][j|(1<<k)],dp[i][j]+A[i].second[k]);
            }
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<P;j++){
            A[i].second[j]-=A[i].first;
        }
    }
    
    reverse(all(A));
    
    for(int i=0;i<=N;i++){
        for(int j=0;j<1<<P;j++){
            dp2[i][j]=-INF;
        }
    }
    dp2[0][0]=0;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<1<<P;j++){
            dp2[i+1][j]=max(dp2[i+1][j],dp2[i][j]);
            for(int k=0;k<P;k++){
                if(j&(1<<k)) continue;
                dp2[i+1][j|(1<<k)]=max(dp2[i+1][j|(1<<k)],dp2[i][j]+A[i].second[k]);
            }
        }
    }
    
    for(int i=0;i<N;i++){
        sum[i+1]=sum[i]+A[i].first;
    }
    
    ll ans=0;
    
    for(int i=K;i<=K+P;i++){
        for(int j=0;j<1<<P;j++){
            if(__builtin_popcount(j)!=i-K) continue;
            
            ans=max(ans,sum[i]+dp2[i][j]+dp[N-i][(1<<P)-1-j]);
            
            //cout<<i<<" "<<j<<" "<<ans<<" "<<sum[i]<<" "<<dp2[i][j]<<" "<<dp[N-i][(1<<P)-1-j]<<endl;
        }
    }
    
    cout<<ans<<endl;
}