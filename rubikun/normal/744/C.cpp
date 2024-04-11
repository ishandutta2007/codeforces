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
const int mod=998244353,MAX=300005,INF=1<<30;

int dp[1<<16][160];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N),B(N);
    vector<int> f(N);
    int sa=0,sb=0;
    for(int i=0;i<N;i++){
        char c;cin>>c;
        if(c=='R') f[i]=0;
        else f[i]=1;
        cin>>A[i]>>B[i];
        sa+=A[i];
        sb+=B[i];
    }
    
    for(int bit=0;bit<(1<<N);bit++) for(int i=0;i<140;i++) dp[bit][i]=-INF;
    dp[0][0]=0;
    
    for(int bit=0;bit<(1<<N);bit++){
        int ra=0,rb=0;
        for(int i=0;i<N;i++){
            if(bit&(1<<i)){
                if(f[i]) rb++;
                else ra++;
            }
        }
        for(int a=0;a<140;a++){
            if(dp[bit][a]<0) continue;
            int b=dp[bit][a];
            for(int i=0;i<N;i++){
                if(bit&(1<<i)) continue;
                int na=a+min(ra,A[i]),nb=b+min(rb,B[i]);
                chmax(dp[bit|(1<<i)][na],nb);
            }
        }
    }
    
    int ans=INF;
    
    for(int a=0;a<140;a++){
        if(dp[(1<<N)-1][a]<0) continue;
        int b=dp[(1<<N)-1][a];
        chmin(ans,N+max(sa-a,sb-b));
    }
    
    cout<<ans<<endl;
}