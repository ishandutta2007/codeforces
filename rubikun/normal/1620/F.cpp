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
const int mod=998244353,MAX=1000005,INF=1<<30;
int dp[MAX][2];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> P(N);
        for(int i=0;i<N;i++){
            cin>>P[i];
            dp[i+1][0]=dp[i+1][1]=INF;
        }
        dp[0][0]=dp[0][1]=-INF;
        for(int i=1;i<N;i++){
            if(-P[i-1]<-P[i]){
                chmin(dp[i][0],dp[i-1][0]);
            }
            if(-P[i-1]<P[i]){
                chmin(dp[i][1],dp[i-1][0]);
            }
            if(P[i-1]<P[i]){
                chmin(dp[i][1],dp[i-1][1]);
            }
            if(dp[i-1][0]<-P[i]){
                chmin(dp[i][0],-P[i-1]);
            }
            if(dp[i-1][0]<P[i]){
                chmin(dp[i][1],-P[i-1]);
            }
            if(dp[i-1][1]<-P[i]){
                chmin(dp[i][0],P[i-1]);
            }
            if(dp[i-1][1]<P[i]){
                chmin(dp[i][1],P[i-1]);
            }
        }
        
        if(dp[N-1][0]!=INF||dp[N-1][1]!=INF){
            cout<<"YES\n";
            int t;
            if(dp[N-1][0]!=INF) t=0;
            else t=1;
            vector<int> ans;
            for(int i=N-1;i>=1;i--){
                if(t==0){
                    if(dp[i][0]==dp[i-1][0]){
                        t=0;
                    }else if(dp[i][0]==-P[i-1]){
                        t=0;
                    }else{
                        t=1;
                    }
                    ans.push_back(-P[i]);
                }else{
                    if(dp[i][1]==dp[i-1][0]){
                        t=0;
                    }else if(dp[i][1]==dp[i-1][1]){
                        t=1;
                    }else if(dp[i][1]==-P[i-1]){
                        t=0;
                    }else{
                        t=1;
                    }
                    ans.push_back(P[i]);
                }
            }
            ans.push_back(-P[0]);
            reverse(all(ans));
            
            for(int a:ans) cout<<a<<" ";
            cout<<"\n";
        }else{
            cout<<"NO\n";
        }
    }
}