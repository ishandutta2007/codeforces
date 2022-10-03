#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;
ll dp[MAX];

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,M;cin>>N>>M;
    dp[1]=1;dp[2]=2;
    
    for(int i=3;i<MAX;i++){
        dp[i]=(dp[i-2]+dp[i-1])%mod;
    }
    
    cout<<(dp[M]*2+(dp[N]+mod-1)*2)%mod<<endl;
}