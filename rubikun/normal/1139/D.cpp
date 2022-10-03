#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

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

ll rui(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}

vector<vector<int>> use(MAX,vector<int>());

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int M;cin>>M;
    sieve(M);
    
    //for(int i=2;i<=M;i++) cout<<cnt[i]<<endl;
    dp[1]=0;
    for(int p:prime){
        for(int j=1;p*j<=M;j++){
            use[p*j].push_back(p);
        }
    }
    
    
    for(ll i=2;i<=M;i++){
        ll sum=0;
        for(ll j=2;j*j<=i;j++){
            if(i%j) continue;
            
            ll k=i/j;
            
            int now=k;
            
            ll cnt=M/j;
            
            int N=use[i/j].size();
            for(int bit=1;bit<(1<<N);bit++){
                int s=1;
                for(int l=0;l<N;l++){
                    if(bit&(1<<l)) s*=use[i/j][l];
                }
                
                if(__builtin_popcount(bit)%2==1) cnt-=M/j/s;
                else cnt+=M/j/s;
            }
            
            sum+=cnt*dp[j];
            sum%=mod;
            
            if(j*j==i) continue;
            
            k=j;
            now=k;
            
            cnt=M/(i/j);
            
            N=use[j].size();
            for(int bit=1;bit<(1<<N);bit++){
                int s=1;
                for(int l=0;l<N;l++){
                    if(bit&(1<<l)) s*=use[j][l];
                }
                
                if(__builtin_popcount(bit)%2==1) cnt-=M/(i/j)/s;
                else cnt+=M/(i/j)/s;
            }
            
            sum+=cnt*dp[i/j];
            sum%=mod;
        }
        dp[i]=(M+sum)%mod*rui(M-M/i,mod-2)%mod;
        //cout<<sum<<" ";
        //cout<<dp[i]<<endl;
    }
    
    ll ans=0;
    for(int i=1;i<=M;i++){
        ans+=dp[i];
        ans%=mod;
    }
    ans*=rui(M,mod-2);
    ans%=mod;
    ans++;
    
    cout<<ans<<endl;
    
    //cout<<3*rui(2,mod-2)%mod<<endl;
}