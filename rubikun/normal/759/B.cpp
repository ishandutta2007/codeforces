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
const int mod=998244353,MAX=100005;
const ll INF=1LL<<60;

ll dp[MAX];

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> t(N+1);
    t[0]=-INF;
    for(int i=1;i<=N;i++) cin>>t[i];
    for(int i=1;i<=N;i++) dp[i]=INF;
    
    for(int i=1;i<=N;i++){
        chmin(dp[i],dp[i-1]+20);
        for(int j=i-1;j>=0;j--){
            if(t[i]-t[j]<=89) chmin(dp[i],dp[j-1]+50);
            else break;
        }
        for(int j=i-1;j>=0;j--){
            if(t[i]-t[j]<=1439) chmin(dp[i],dp[j-1]+120);
            else break;
        }
    }
    
    for(int i=1;i<=N;i++) cout<<dp[i]-dp[i-1]<<"\n";
}