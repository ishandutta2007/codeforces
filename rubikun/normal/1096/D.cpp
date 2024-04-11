#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=100001;
const ll INF=1LL<<55;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    string S;cin>>S;
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    ll dp[N+1][4];
    for(int i=0;i<N+1;i++){
        for(int j=0;j<4;j++){
            dp[i][j]=INF;
            if(i==0) dp[i][j]=0;
        }
    }
    
    for(int i=0;i<N;i++){
        if(S[i]=='h'){
            dp[i+1][0]=dp[i][0]+A[i];
            dp[i+1][1]=min(dp[i][0],dp[i][1]);
            dp[i+1][2]=dp[i][2];
            dp[i+1][3]=dp[i][3];
        }else if(S[i]=='a'){
            dp[i+1][0]=dp[i][0];
            dp[i+1][1]=dp[i][1]+A[i];
            dp[i+1][2]=min(dp[i][1],dp[i][2]);
            dp[i+1][3]=dp[i][3];
        }else if(S[i]=='r'){
            dp[i+1][0]=dp[i][0];
            dp[i+1][1]=dp[i][1];
            dp[i+1][2]=dp[i][2]+A[i];
            dp[i+1][3]=min(dp[i][2],dp[i][3]);
        }else if(S[i]=='d'){
            dp[i+1][0]=dp[i][0];
            dp[i+1][1]=dp[i][1];
            dp[i+1][2]=dp[i][2];
            dp[i+1][3]=dp[i][3]+A[i];
        }else{
            dp[i+1][0]=dp[i][0];
            dp[i+1][1]=dp[i][1];
            dp[i+1][2]=dp[i][2];
            dp[i+1][3]=dp[i][3];
        }
    }
    
    cout<<min({dp[N][0],dp[N][1],dp[N][2],dp[N][3]})<<endl;
    
}