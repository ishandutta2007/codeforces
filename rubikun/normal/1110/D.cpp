#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=1000003,INF=1<<30;

int dp[MAX][7][7];

int main(){
    
    int N,M;cin>>N>>M;
    vector<int> cnt(M+1,0);
    
    for(int i=0;i<M+1;i++){
        for(int j=0;j<7;j++){
            for(int k=0;k<7;k++){
                dp[i][j][k]=-INF;
            }
        }
    }
    dp[0][0][0]=0;
    
    for(int i=0;i<N;i++){
        int a;//cin>>a;
        scanf("%d",&a);
        cnt[a]++;
    }
    
    int ans=0;
    
    for(int i=1;i<=M;i++){
        if(cnt[i]>=9){
            int pl=(cnt[i]-9)/3;
            ans+=pl;
            cnt[i]-=3*pl;
        }
    }
    
    for(int i=1;i<=M;i++){
        for(int j=0;j<7;j++){
            for(int k=0;k<7;k++){
                int mini=min({j,k,cnt[i]});
                for(int l=0;l<=mini;l++){
                    dp[i][k-l][cnt[i]-l]=max(dp[i][k-l][cnt[i]-l],dp[i-1][j][k]+l);
                }
            }
        }
        if(cnt[i]>=3){
            for(int j=0;j<7;j++){
                for(int k=0;k<7;k++){
                    int mini=min({j,k,cnt[i]-3});
                    for(int l=0;l<=mini;l++){
                        dp[i][k-l][cnt[i]-3-l]=max(dp[i][k-l][cnt[i]-3-l],dp[i-1][j][k]+l+1);
                    }
                }
            }
        }
        if(cnt[i]>=6){
            for(int j=0;j<7;j++){
                for(int k=0;k<7;k++){
                    int mini=min({j,k,cnt[i]-6});
                    for(int l=0;l<=mini;l++){
                        dp[i][k-l][cnt[i]-6-l]=max(dp[i][k-l][cnt[i]-6-l],dp[i-1][j][k]+l+2);
                    }
                }
            }
        }
        if(cnt[i]>=9){
            for(int j=0;j<7;j++){
                for(int k=0;k<7;k++){
                    int mini=min({j,k,cnt[i]-9});
                    for(int l=0;l<=mini;l++){
                        dp[i][k-l][cnt[i]-9-l]=max(dp[i][k-l][cnt[i]-9-l],dp[i-1][j][k]+l+3);
                    }
                }
            }
        }
    }
    
    int maxi=0;
    
    for(int j=0;j<7;j++){
        for(int k=0;k<7;k++){
            maxi=max(maxi,dp[M][j][k]);
        }
    }
    
    cout<<ans+maxi<<endl;
}