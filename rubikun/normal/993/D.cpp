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
const int mod=1000000007,MAX=55;
const ll INF=1LL<<60;

ll dp[MAX][MAX][MAX*100];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<pair<ll,ll>> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i].fi;
    }
    for(int i=0;i<N;i++){
        cin>>A[i].se;
    }
    sort(all(A),[](auto a,auto b){
        if(a.fi==b.fi) return a.se>b.se;
        return a.fi<b.fi;
    });
    
    for(int i=0;i<MAX;i++) for(int j=0;j<MAX;j++) for(int k=0;k<MAX*100;k++) dp[i][j][k]=INF;
    dp[0][0][0]=0;
    
    for(int i=0;i<N;){
        int to=i;
        while(to<N&&A[i].fi==A[to].fi) to++;
        
        vector<ll> sum(to-i+1);
        sum[0]=0;
        for(int j=1;j<si(sum);j++){
            sum[j]=sum[j-1]+A[i+j-1].se;
        }
        
        for(int j=0;j<=i;j++){
            for(int k=0;k<=100*i;k++){
                if(dp[i][j][k]==INF) continue;
                
                for(int l=0;l<=to-i;l++){
                    int use=to-i-l;
                    chmin(dp[to][max(0,j-use)+l][k+sum[use]],dp[i][j][k]+A[i].fi*use);
                }
            }
        }
        i=to;
    }
    
    ll ans=INF;
    
    for(int k=1;k<=100*N;k++){
        if(dp[N][0][k]==INF) continue;
        chmin(ans,(dp[N][0][k]*1000+k-1)/k);
    }
    
    cout<<ans<<endl;
}