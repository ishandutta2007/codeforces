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
const int mod=1000000007,MAX=305,INF=1<<30;

ll dp[MAX][MAX][MAX];

ll inv[MAX],fac[MAX],finv[MAX];

void make(){
    
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    
    for(int i=2;i<MAX;i++){
        inv[i]=mod-inv[mod%i]*(mod/i)%mod;
        fac[i]=fac[i-1]*(ll)i%mod;
        finv[i]=finv[i-1]*inv[i]%mod;
    }
    
}

ll comb(ll a,ll b){
    if(a<b) return 0;
    return fac[a]*(finv[b]*finv[a-b]%mod)%mod;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    make();
    
    int N;cin>>N;
    
    vector<ll> A(N),cnt(N),B;
    for(int i=0;i<N;i++) cin>>A[i];
    
    for(int i=0;i<N;i++){
        if(cnt[i]==-1) continue;
        
        cnt[i]=1;
        
        for(int j=i+1;j<N;j++){
            if(cnt[j]==-1) continue;
            
            ll s=A[i]*A[j];
            ll d=sqrt(s);
            if((d-1)*(d-1)==s||d*d==s||(d+1)*(d+1)==s){
                cnt[j]=-1;
                cnt[i]++;
            }
        }
    }
    
    for(int i=0;i<N;i++) if(cnt[i]>=1) B.push_back(cnt[i]);
    
    sort(all(B));
    
    dp[0][0][0]=1;
    
    int sum=0;
    
    for(int i=0;i<si(B);i++){
        for(int t=0;t<B[i];t++){
            for(int j=0;j<=t;j++){
                for(int k=j;k<=N;k++){
                    if(dp[sum+t][j][k]==0) continue;
                    
                    int all=sum+t+1;
                    
                    if(t==0){
                        dp[sum+t+1][j][k]+=dp[sum+t][j][k]*(all-k);
                        dp[sum+t+1][j][k]%=mod;
                        
                        if(k) dp[sum+t+1][j][k-1]+=dp[sum+t][j][k]*k;
                        if(k) dp[sum+t+1][j][k-1]%=mod;
                        
                        continue;
                    }
                    
                    dp[sum+t+1][j+1][k+1]+=dp[sum+t][j][k]*(2*t-j);
                    dp[sum+t+1][j+1][k+1]%=mod;
                    
                    if(k) dp[sum+t+1][j][k-1]+=dp[sum+t][j][k]*(k-j);
                    if(k) dp[sum+t+1][j][k-1]%=mod;
                    
                    dp[sum+t+1][j][k]+=dp[sum+t][j][k]*(all-(2*t-j)-(k-j));
                    dp[sum+t+1][j][k]%=mod;
                }
            }
        }
        
        sum+=B[i];
        
        for(int j=1;j<=B[i];j++){
            for(int k=N;k>=0;k--){
                dp[sum][0][k]+=dp[sum][j][k];
                dp[sum][0][k]%=mod;
                
                dp[sum][j][k]=0;
            }
        }
    }
    
    cout<<dp[N][0][0]<<endl;
}