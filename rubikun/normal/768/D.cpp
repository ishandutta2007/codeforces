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
const int mod=1000000007,MAX=1005;
const ll INF=1LL<<60;

#define ld long double

ld dp[10005][1005];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    dp[0][0]=1;
    int K,Q;cin>>K>>Q;
    for(int t=0;t<10000;t++){
        for(int i=0;i<=K;i++){
            dp[t+1][i]+=dp[t][i]*i/K;
            dp[t+1][i+1]+=dp[t][i]*(K-i)/K;
        }
    }
    
    while(Q--){
        int x;cin>>x;
        for(int t=0;t<=10000;t++){
            if(dp[t][K]>=((ld)(x)-1e-7)/2000){
                cout<<t<<"\n";
                break;
            }
        }
    }
}