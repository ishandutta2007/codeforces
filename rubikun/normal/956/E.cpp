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
const int mod=1000000007,MAX=20005,INF=1<<30;
int dp[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,l,r;cin>>N>>l>>r;
    vector<int> A(N),B(N),C;
    int S=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        S+=A[i];
    }
    for(int i=0;i<N;i++){
        cin>>B[i];
        if(B[i]) C.push_back(A[i]);
    }
    
    dp[0]=0;
    for(int i=1;i<MAX;i++) dp[i]=-INF;
    
    for(int i=0;i<N;i++){
        for(int j=10000;j>=A[i];j--){
            if(B[i]) continue;
            chmax(dp[j],dp[j-A[i]]);
        }
    }
    
    sort(all(C));
    reverse(all(C));
    
    for(int a:C){
        for(int j=10000;j>=a;j--){
            if(S-r<=j&&j<=S-l) chmax(dp[j],dp[j-a]+1);
            else chmax(dp[j],dp[j-a]);
        }
    }
    
    int ans=0;
    for(int j=0;j<MAX;j++) chmax(ans,dp[j]);
    
    cout<<ans<<endl;
}