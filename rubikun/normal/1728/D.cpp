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
const int mod=998244353,MAX=2005,INF=1<<30;

bool seen[MAX][MAX];
int dp[MAX][MAX];
string S;

int solve(int l,int r){
    if(seen[l][r]) return dp[l][r];
    if(l+2==r){
        if(S[l]==S[l+1]) return dp[l][r]=0;
        else return dp[l][r]=1;
    }
    seen[l][r]=true;
    
    int aa=solve(l+2,r),ab=solve(l+1,r-1),ba=solve(l+1,r-1),bb=solve(l,r-2);
    if(aa==0){
        if(S[l]>S[l+1]) aa=-1;
        if(S[l]<S[l+1]) aa=1;
    }
    if(ab==0){
        if(S[l]>S[r-1]) ab=-1;
        if(S[l]<S[r-1]) ab=1;
    }
    if(ba==0){
        if(S[r-1]>S[l]) ba=-1;
        if(S[r-1]<S[l]) ba=1;
    }
    if(bb==0){
        if(S[r-1]>S[r-2]) bb=-1;
        if(S[r-1]<S[r-2]) bb=1;
    }
    //cout<<l<<" "<<r<<" "<<aa<<" "<<ab<<" "<<ba<<" "<<bb<<endl;
    if(aa==1&&ab==1) return dp[l][r]=1;
    if(ba==1&&bb==1) return dp[l][r]=1;
    if(aa>=0&&ab>=0) return dp[l][r]=0;
    if(ba>=0&&bb>=0) return dp[l][r]=0;
    return dp[l][r]=-1;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        cin>>S;
        int N=si(S);
        for(int i=0;i<=N;i++) for(int j=0;j<=N;j++) seen[i][j]=dp[i][j]=0;
        int res=solve(0,N);
        if(res==1) cout<<"Alice\n";
        else if(res==0) cout<<"Draw\n";
        else cout<<"Bob\n";
    }
    
}