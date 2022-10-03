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

int dp[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        A.push_back(0);
        for(int i=0;i<=N;i++) dp[i]=-INF;
        
        map<int,int> MA;
        MA[0]=0;
        
        dp[0]=0;
        
        int X=0;
        for(int i=0;i<N;i++){
            X^=A[i];
            if(MA.count(X)){
                int la=MA[X];
                chmax(dp[i+1],dp[la]+1);
            }
            chmax(dp[i+1],dp[i]);
            
            MA[X]=i+1;
        }
        
        cout<<N-dp[N]<<"\n";
    }
}