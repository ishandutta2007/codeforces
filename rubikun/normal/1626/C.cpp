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
const int mod=998244353,MAX=105;
const ll INF=1LL<<60;
ll dp[MAX];

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<ll> t(N+1),h(N+1);
        for(int i=0;i<N;i++) cin>>t[i+1];
        for(int i=0;i<N;i++) cin>>h[i+1];
        for(int i=1;i<=N;i++) dp[i]=INF;
        for(int i=1;i<=N;i++){
            for(int j=0;j<i;j++){
                ll mi=INF;
                for(int k=j+1;k<=i;k++) chmin(mi,t[k]-h[k]);
                mi++;
                if(t[j]<mi&&mi<=t[j+1]){
                    ll x=t[i]-(mi-1);
                    chmin(dp[i],dp[j]+x*(x+1)/2);
                }
            }
        }
        
        cout<<dp[N]<<"\n";
    }
}