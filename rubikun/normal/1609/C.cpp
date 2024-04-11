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
const int mod=998244353,MAX=1000005,INF=1<<30;

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

int cnt[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    sieve(MAX-2);
    int Q;cin>>Q;
    while(Q--){
        int N,K;cin>>N>>K;
        ll ans=0;
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        
        for(int t=0;t<K;t++){
            vector<int> pos;
            for(int i=t;i<N;i+=K){
                if(is_prime[A[i]]){
                    int j=i-K;
                    while(j>=0&&A[j]==1) j-=K;
                    int k=i+K;
                    while(k<N&&A[k]==1) k+=K;
                    ll l=(i-j)/K,r=(k-i)/K;
                    ans+=l*r-1;
                }
            }
        }
        
        //for(int i=0;i<N;i++) if(is_prime[A[i]]) ans--;
        
        cout<<ans<<"\n";
    }
}