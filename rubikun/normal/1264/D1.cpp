#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=2005;
const ll INF=1LL<<60;

ll rui(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}

ll dp[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S;cin>>S;
    int N=int(S.size());
    
    vector<int> cnt(N+2);
    for(int i=0;i<N;i++){
        if(S[i]=='?') cnt[i+1]++;
        cnt[i+1]+=cnt[i];
    }
    
    for(int len=1;len<N;len++){
        for(int l=1;l<=N;l++){
            int r=l+len;
            if(r>N) continue;
            
            if(S[l-1]=='('){
                if(S[r-1]=='(') dp[l][r]+=dp[l][r-1];
                if(S[r-1]==')') dp[l][r]+=dp[l+1][r-1]+rui(2,cnt[r-1]-cnt[l]);
                if(S[r-1]=='?'){
                    dp[l][r]+=dp[l][r-1];
                    dp[l][r]+=dp[l+1][r-1]+rui(2,cnt[r-1]-cnt[l]);
                }
            }else if(S[l-1]==')'){
                if(S[r-1]=='('){
                    dp[l][r]+=dp[l][r-1];
                    dp[l][r]+=dp[l+1][r];
                    dp[l][r]+=mod-dp[l+1][r-1];
                }
                if(S[r-1]==')') dp[l][r]+=dp[l+1][r];
                if(S[r-1]=='?'){
                    dp[l][r]+=dp[l][r-1];
                    dp[l][r]+=dp[l+1][r];
                    dp[l][r]+=mod-dp[l+1][r-1];
                }
            }else{
                if(S[r-1]=='('){
                    dp[l][r]+=dp[l][r-1];
                    dp[l][r]+=dp[l+1][r];
                    dp[l][r]+=mod-dp[l+1][r-1];
                }
                if(S[r-1]==')'){
                    dp[l][r]+=dp[l+1][r-1]+rui(2,cnt[r-1]-cnt[l]);
                    dp[l][r]+=dp[l+1][r];
                }
                if(S[r-1]=='?'){
                    dp[l][r]+=dp[l][r-1];
                    dp[l][r]+=dp[l+1][r];
                    dp[l][r]+=mod-dp[l+1][r-1];
                    dp[l][r]+=dp[l+1][r-1]+rui(2,cnt[r-1]-cnt[l]);
                }
            }
            
            dp[l][r]%=mod;
        }
    }
    
    cout<<dp[1][N]<<endl;
}