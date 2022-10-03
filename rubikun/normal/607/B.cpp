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
const int mod=998244353,MAX=505,INF=1<<30;

int N;
bool seen[MAX][MAX];
int dp[MAX][MAX];
int c[MAX];
bool ok[MAX][MAX];

int solve(int l,int r){
    if(ok[l][r]) return 1;
    if(seen[l][r]) return dp[l][r];
    seen[l][r]=true;
    int res=INF;
    if(c[l]==c[r-1]) chmin(res,solve(l+1,r-1));
    for(int m=l+1;m<=r;m++){
        if(ok[l][m]) chmin(res,solve(m,r)+1);
    }
    for(int m=l;m<r;m++){
        if(ok[m][r]) chmin(res,solve(l,m)+1);
    }
    for(int m=l+1;m<r;m++) chmin(res,solve(l,m)+solve(m,r));
    return dp[l][r]=res;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>c[i];c[i]--;
    }
    for(int l=0;l<N;l++){
        for(int r=l+1;r<=N;r++){
            vector<int> A;
            for(int k=l;k<r;k++) A.push_back(c[k]);
            vector<int> B=A;reverse(all(B));
            if(A==B) ok[l][r]=true;
        }
    }
    cout<<solve(0,N)<<endl;
}