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
const int mod=1000000007,MAX=105,INF=1<<30;

double dp[1<<20];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,K;cin>>N>>K;
    vector<double> P(N);
    int sz=0;
    for(int i=0;i<N;i++){
        cin>>P[i];
        if(P[i]!=0) sz++;
    }
    
    if(sz<=K){
        for(int i=0;i<N;i++){
            if(P[i]!=0) cout<<1<<" ";
            else cout<<0<<" ";
        }
        cout<<endl;
        return 0;
    }
    
    dp[0]=1;
    for(int bit=0;bit<(1<<N);bit++){
        double rem=0;
        for(int i=0;i<N;i++){
            if(!(bit&(1<<i))) rem+=P[i];
        }
        if(rem==0) continue;
        
        for(int i=0;i<N;i++){
            if(!(bit&(1<<i))) dp[bit|(1<<i)]+=dp[bit]*P[i]/rem;
        }
    }
    
    vector<double> ans(N);
    
    for(int bit=0;bit<(1<<N);bit++){
        if(__builtin_popcount(bit)==K){
            for(int i=0;i<N;i++){
                if(bit&(1<<i)) ans[i]+=dp[bit];
            }
        }
    }
    
    for(int i=0;i<N;i++) cout<<fixed<<setprecision(25)<<ans[i]<<" ";
    cout<<endl;
}