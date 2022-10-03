#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=1000005;
const ll INF=1LL<<62;
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
    
    sieve(MAX-2);
    int X;cin>>X;
    vector<int> can(MAX-2);
    for(int p:prime){
        if(X%p==0){
            for(int i=(X/p-1)*p+1;i<=X;i++) can[i]=1;
        }
    }
    
    int ans=X;
    
    for(int p:prime){
        for(int i=2;p*i<=1000000;i++){
            if(can[p*i]){
                chmin(ans,p*(i-1)+1);
            }
        }
    }
    
    cout<<ans<<endl;
}