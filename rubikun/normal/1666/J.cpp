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
const int mod=998244353,MAX=205;
const ll INF=1LL<<60;

ll S[MAX][MAX];
bool seen[MAX][MAX];
ll dp[MAX][MAX];

ll solve(int l,int r){
    if(seen[l][r]) return dp[l][r];
    if(l==r) return 0;
    if(l+1==r) return 0;
    seen[l][r]=true;
    ll res=INF;
    for(int m=l;m<r;m++){
        chmin(res,solve(l,m)+solve(m+1,r)+S[l][m]+S[m+1][r]);
    }
    return dp[l][r]=res;
}

int ans[MAX];

void huku(int l,int r,int p){
    if(l==r) return;
    if(l+1==r){
        ans[l]=p;
        return;
    }
    int to=-1;
    for(int m=l;m<r;m++){
        if(dp[l][r]==solve(l,m)+solve(m+1,r)+S[l][m]+S[m+1][r]) to=m;
    }
    ans[to]=p;
    huku(l,to,to);
    huku(to+1,r,to);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<vector<ll>> A(N,vector<ll>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>A[i][j];
        }
    }
    for(int l=0;l<N;l++){
        for(int r=l+1;r<=N;r++){
            ll sum=0;
            for(int i=l;i<r;i++){
                for(int j=0;j<l;j++) sum+=A[i][j];
                for(int j=r;j<N;j++) sum+=A[i][j];
            }
            S[l][r]=sum;
        }
    }
    
    solve(0,N);
    huku(0,N,-1);
    
    for(int i=0;i<N;i++) cout<<ans[i]+1<<" ";
    cout<<endl;
}