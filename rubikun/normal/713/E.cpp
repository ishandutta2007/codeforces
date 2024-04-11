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
const int mod=998244353,MAX=100005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int M,N;cin>>M>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];A[i]--;
    }
    sort(all(A));
    
    for(int i=N-1;i>=0;i--){
        A[i]-=A[0];
    }
    
    A.push_back(M);
    
    int left=-1,right=-1;
    for(int i=0;i<N;i++){
        chmax(right,A[i+1]-A[i]-1);
    }
    
    vector<int> B=A;
    reverse(all(B));
    B.pop_back();
    for(int i=0;i<N;i++) B[i]=M-B[i];
    
    while(right-left>1){
        int mid=(left+right)/2;
        bool f=false;
        {
            vector<int> dp(N+4,-INF);
            dp[1]=mid;
            for(int i=1;i<N;i++){
                if(dp[i]>=A[i]-1) chmax(dp[i+1],A[i]+mid);
                if(dp[i]+1>=A[i]-mid) chmax(dp[i+1],A[i]);
                if(i+1<N&&dp[i]+1>=A[i+1]-mid) chmax(dp[i+2],A[i]+mid);
            }
            if(dp[N]>=M-1) f=true;
        }
        {
            vector<int> dp(N+4,-INF);
            dp[1]=mid;
            for(int i=1;i<N;i++){
                if(dp[i]>=B[i]-1) chmax(dp[i+1],B[i]+mid);
                if(dp[i]+1>=B[i]-mid) chmax(dp[i+1],B[i]);
                if(i+1<N&&dp[i]+1>=B[i+1]-mid) chmax(dp[i+2],B[i]+mid);
            }
            if(dp[N]>=M-1) f=true;
        }
        {
            vector<int> dp(N+4,-INF);
            dp[2]=mid;
            for(int i=2;i<N;i++){
                if(dp[i]>=A[i]-1) chmax(dp[i+1],A[i]+mid);
                if(dp[i]+1>=A[i]-mid) chmax(dp[i+1],A[i]);
                if(i+1<N&&dp[i]+1>=A[i+1]-mid) chmax(dp[i+2],A[i]+mid);
            }
            if(dp[N]>=M+A[1]-1-mid) f=true;
        }
        {
            vector<int> dp(N+4,-INF);
            dp[2]=mid;
            for(int i=2;i<N;i++){
                if(dp[i]>=B[i]-1) chmax(dp[i+1],B[i]+mid);
                if(dp[i]+1>=B[i]-mid) chmax(dp[i+1],B[i]);
                if(i+1<N&&dp[i]+1>=B[i+1]-mid) chmax(dp[i+2],B[i]+mid);
            }
            if(dp[N]>=M+B[1]-1-mid) f=true;
        }
        if(f) right=mid;
        else left=mid;
    }
    /*
    for(int i=0;i<N;i++) cout<<A[i]<<" ";
    cout<<endl;
    for(int i=0;i<N;i++) cout<<B[i]<<" ";
    cout<<endl;
     */
    
    cout<<right<<endl;
}