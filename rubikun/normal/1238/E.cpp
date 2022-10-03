#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<20,INF=1<<30;
int dp[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    string S;cin>>S;
    
    vector<vector<int>> cnt(M,vector<int>(M));
    vector<int> sum((1<<M));
    
    for(int i=1;i<S.size();i++){
        cnt[S[i-1]-'a'][S[i]-'a']++;
    }
    dp[0]=0;
    
    for(int bit=0;bit<(1<<(M-1));bit++){
        vector<int> l,r;
        for(int i=0;i<M;i++){
            if(bit&(1<<i)) l.push_back(i);
            else r.push_back(i);
        }
        for(int a:l){
            for(int b:r){
                sum[bit]+=cnt[a][b];
                sum[bit]+=cnt[b][a];
            }
        }
        sum[(1<<M)-1-bit]=sum[bit];
    }
    
    for(int i=1;i<(1<<M);i++) dp[i]=INF;
    
    for(int bit=0;bit<(1<<M);bit++){
        for(int i=0;i<M;i++){
            if(bit&(1<<i)) continue;
            
            dp[bit|(1<<i)]=min(dp[bit|(1<<i)],dp[bit]+sum[bit|(1<<i)]);
        }
    }
    
    cout<<dp[(1<<M)-1]<<endl;
}