#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=403,INF=1<<30;

int prime[MAX];//i
bool is_prime[MAX+1];

void sieve(int n){
    int p=0;
    for(int i=0;i<=n;i++){
        is_prime[i]=true;
    }
    
    is_prime[0]=is_prime[1]=false;
    
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            prime[p++] = i;
            for(int j=2*i;j<=n;j+=i){
                is_prime[j] = false;
            }
        }
    }
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,K;cin>>N>>K;
    
    sieve(400);
    
    map<vector<int>,ll> MA;
    
    ll ans=0;
    
    for(int i=0;i<N;i++){
        int a;cin>>a;
        vector<int> cnt(81,0),search(81,0);
        for(int j=0;j<78;j++){
            while(a%prime[j]==0){
                cnt[j]++;
                if(cnt[j]>=K) cnt[j]-=K;
                a/=prime[j];
            }
        }
        if(a!=1) cnt[80]=a;
        
        for(int j=0;j<78;j++){
            if(cnt[j]==0) search[j]=0;
            else search[j]=K-cnt[j];
        }
        
        search[80]=cnt[80];
        
        if(cnt[80]){
            if(K==2) ans+=MA[search];
        }
        
        else ans+=MA[search];
        
        MA[cnt]++;
    }
    
    cout<<ans<<endl;
    
}