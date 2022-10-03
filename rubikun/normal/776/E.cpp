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

ll f(ll n){
    ll rem=n,res=n;
    for(int p:prime){
        if(p>n) break;
        if(n%p==0){
            while(rem%p==0) rem/=p;
            res=res/p*(p-1);
        }
    }
    if(rem!=1){
        res=res/rem*(rem-1);
    }
    return res;
}

ll solve(ll n,ll k){
    //
    if(n==1) return 1;
    if(k==1){
        return f(n);
    }
    if(k%2==0){
        return solve(n,k-1);
    }else{
        return f(solve(n,k-1));
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    sieve(MAX-2);
    ll N,K;cin>>N>>K;
    if(K>=100){
        if(K&1LL) K=101;
        else K=100;
    }
    cout<<solve(N,K)%mod<<endl;
}