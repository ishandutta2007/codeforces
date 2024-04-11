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
const int mod=1000000007,MAX=1000005;
const ll INF=1LL<<60;

vector<int> prime;//i
bool is_prime[MAX+1];

void sieve(int n){
    for(int i=0;i<=n;i++){
        is_prime[i]=true;
    }
    
    is_prime[0]=is_prime[1]=false;
    
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            prime.push_back(i);
            for(int j=2*i;j<=n;j+=i){
                is_prime[j] = false;
            }
        }
    }
}

ll dp[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    sieve(MAX-2);
    int N;cin>>N;
    ll a,b;cin>>a>>b;
    ll ans=INF;
    vector<int> S(N);
    for(int i=0;i<N;i++) cin>>S[i];
    
    for(int q=0;q<2;q++){
        vector<int> cand;
        for(int d=-1;d<=1;d++){
            int X=S[0]+d;
            for(int p:prime){
                if(X%p==0){
                    cand.push_back(p);
                    while(X%p==0){
                        X/=p;
                    }
                }
            }
            if(X>1) cand.push_back(X);
        }
        sort(all(cand));
        cand.erase(unique(all(cand)),cand.end());
        
        for(int p:cand){
            for(int i=0;i<=N;i++) dp[i]=INF;
            dp[N]=0;
            for(int i=N-1;i>=0;i--){
                if((S[i]+1)%p==0) chmin(dp[i],dp[i+1]+b-a);
                if(S[i]%p==0) chmin(dp[i],dp[i+1]-a);
                if((S[i]-1)%p==0) chmin(dp[i],dp[i+1]+b-a);
            }
            for(int i=N-1;i>=0;i--) chmin(dp[i],dp[i+1]);
            
            ll cost=0;
            for(int i=0;i<N;i++){
                if(S[i]%p==0){
                    chmin(ans,cost-a+dp[i+1]+a*N);
                    cost-=a;
                }else if((S[i]+1)%p==0||(S[i]-1)%p==0){
                    chmin(ans,cost+b-a+dp[i+1]+a*N);
                    cost+=b-a;
                }else break;
            }
            
            chmin(ans,a*N+dp[0]);
        }
        
        reverse(all(S));
    }
    
    cout<<ans<<endl;
}