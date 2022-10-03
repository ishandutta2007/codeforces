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
const int mod=998244353,MAX=100005,INF=1<<29;

long double dp[105][100005];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    if(M==1){
        cout<<1<<endl;
        return 0;
    }
    dp[0][0]=1;
    int sum=0;
    for(int i=0;i<N;i++){
        int x;cin>>x;
        sum+=x;
        for(int j=0;j<=M*i;j++){
            dp[i+1][j+1]+=dp[i][j]/(M-1);
            dp[i+1][j+x]-=dp[i][j]/(M-1);
            dp[i+1][j+x+1]+=dp[i][j]/(M-1);
            dp[i+1][j+M+1]-=dp[i][j]/(M-1);
        }
        for(int j=1;j<=M*(i+1);j++) dp[i+1][j]+=dp[i+1][j-1];
    }
    long double ans=0;
    for(int j=0;j<sum;j++) ans+=dp[N][j];
    
    cout<<fixed<<setprecision(25)<<(1.0+ans*(M-1))<<endl;
}