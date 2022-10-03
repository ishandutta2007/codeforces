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
const int mod=1000000007,MAX=20000;
const ll INF=1LL<<60;
#define uint unsigned int
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

uint A,B,C,D;

uint f(uint sum,uint p){
    return sum*(A*p*p*p+B*p*p+C*p+D);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    sieve(20000);
    
    int N;cin>>N>>A>>B>>C>>D;
    
    uint ans=0;
    
    for(int p:prime){
        uint sum=0;
        int rem=N;
        while(rem){
            sum+=rem/p;
            rem/=p;
        }
        ans+=f(sum,p);
    }
    
    for(int i=0;i<=20000;i++) is_prime[i]=1;
    
    for(int t=20001;t<=N;t+=20000){
        int l=t,r=min(N,t+20000-1);
        for(int p:prime){
            for(int j=l/p*p;j<=r;j+=p){
                if(j<l) continue;
                is_prime[j-t+1]=false;
            }
        }
        for(int i=l;i<=r;i++){
            if(is_prime[i-t+1]){
                int p=i;
                ans+=f(N/p,p);
            }else is_prime[i-t+1]=1;
        }
    }
    
    cout<<ans<<endl;
}