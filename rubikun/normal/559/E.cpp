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
const int mod=1000000007,MAX=105;
const ll INF=1LL<<60;

ll dp[MAX][MAX][2];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<pair<ll,ll>> S(N);
    for(int i=0;i<N;i++) cin>>S[i].fi>>S[i].se;
    S.push_back(mp(-INF,0));
    sort(all(S));
    
    vector<ll> A(N+1),L(N+1);
    for(int i=0;i<=N;i++){
        A[i]=S[i].fi;
        L[i]=S[i].se;
    }
    
    for(int i=0;i<MAX;i++) for(int j=0;j<MAX;j++) dp[i][j][0]=dp[i][j][1]=-INF;
    
    dp[0][0][0]=dp[0][0][1]=0;
    
    ll ans=-INF;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            for(int f=0;f<2;f++){
                ll now=A[j]+L[j]*f;
                ll ma=-INF;
                int jj=-1,ff=-1;
                for(int k=i+1;k<=N;k++){
                    for(int g=0;g<2;g++){
                        ll nex=A[k]+L[k]*g;
                        if(chmax(ma,nex)){
                            jj=k;
                            ff=g;
                        }
                        
                        chmax(dp[k][jj][ff],dp[i][j][f]+min(nex-now,L[k])+(ma-nex));
                        chmax(ans,dp[k][jj][ff]);
                    }
                }
            }
        }
    }
    
    cout<<ans<<endl;
    
}