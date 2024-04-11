#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200007,INF=1<<30;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    sieve(200003);
    
    int T;cin>>T;
    while(T--){
        ll A,M;cin>>A>>M;
        ll g=gcd(A,M);
        A/=g;
        M/=g;
        
        vector<ll> p;
        
        ll save=M;
        
        for(int a:prime){
            if(M%a==0) p.push_back(a);
            while(M%a==0) M/=a;
        }
        
        if(M!=1) p.push_back(M);
        
        M=save;
        
        ll sum=0;
        
        for(int bit=0;bit<(1<<(p.size()));bit++){
            ll N=M;
            int cnt=0;
            
            for(int i=0;i<p.size();i++){
                if(bit&(1<<i)){
                    cnt++;
                    N/=p[i];
                }
            }
            
            if(cnt%2==1) sum-=N;
            else sum+=N;
        }
        
        cout<<sum<<endl;
        
        //cout<<M-sum+1<<endl;
    }
}