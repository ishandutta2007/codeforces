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
const int mod=1000000007,MAX=200005;
//const int INF=1<<28;
const ll INF=1LL<<60;
int N,K;
vector<ll> A[3005];
ll ans=0;

void solve(int l,int r,vector<ll> &dp){
    if(l+1==r){
        for(int i=0;i<=min(K,si(A[l])-1);i++){
            chmax(ans,A[l][i]+dp[K-i]);
        }
        return;
    }
    
    int mid=(l+r)/2;
    
    {
        vector<ll> dp2=dp;
        for(int i=l;i<mid;i++){
            for(int j=K;j>=si(A[i])-1;j--){
                chmax(dp2[j],dp2[j-(si(A[i])-1)]+A[i].back());
            }
        }
        solve(mid,r,dp2);
    }
    
    {
        vector<ll> dp2=dp;
        for(int i=mid;i<r;i++){
            for(int j=K;j>=si(A[i])-1;j--){
                chmax(dp2[j],dp2[j-(si(A[i])-1)]+A[i].back());
            }
        }
        solve(l,mid,dp2);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N>>K;
    for(int i=0;i<N;i++){
        int t;cin>>t;
        A[i].resize(t+1);
        for(int j=1;j<=t;j++){
            cin>>A[i][j];
            A[i][j]+=A[i][j-1];
        }
    }
    
    vector<ll> dp(K+1,-INF);
    dp[0]=0;
    solve(0,N,dp);
    
    cout<<ans<<endl;
}