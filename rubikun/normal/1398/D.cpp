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
const int mod=1000000007,MAX=205,INF=1<<30;
ll dp[MAX][MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int A,B,C;cin>>A>>B>>C;
    vector<ll> a(A),b(B),c(C);
    for(int i=0;i<A;i++) cin>>a[i];
    for(int i=0;i<B;i++) cin>>b[i];
    for(int i=0;i<C;i++) cin>>c[i];
    
    a.push_back(0);
    b.push_back(0);
    c.push_back(0);
    
    sort(all(a));
    sort(all(b));
    sort(all(c));
    reverse(all(a));
    reverse(all(b));
    reverse(all(c));
    
    for(int i=0;i<=A;i++){
        for(int j=0;j<=B;j++){
            for(int k=0;k<=C;k++){
                if(i||j||k){
                    if(dp[i][j][k]==0) continue;
                }
                
                chmax(dp[i+1][j+1][k],dp[i][j][k]+a[i]*b[j]);
                chmax(dp[i][j+1][k+1],dp[i][j][k]+b[j]*c[k]);
                chmax(dp[i+1][j][k+1],dp[i][j][k]+a[i]*c[k]);
            }
        }
    }
    
    ll ans=0;
    
    for(int i=0;i<=A;i++){
        for(int j=0;j<=B;j++){
            for(int k=0;k<=C;k++){
                chmax(ans,dp[i][j][k]);
            }
        }
    }
    
    cout<<ans<<endl;
    
}