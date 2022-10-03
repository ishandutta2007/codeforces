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
const int mod=1000000007,MAX=200005,INF=1<<30;

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
    
    sieve(200002);
    
    int N;cin>>N;
    vector<int> A(N);
    
    for(int i=0;i<N;i++) cin>>A[i];
    
    ll ans=1;
    
    for(int p:prime){
        int out=0;
        vector<int> can;
        for(int i=0;i<N;i++){
            int su=0;
            while(A[i]%p==0){
                su++;
                A[i]/=p;
            }
            if(!su) out++;
            else can.push_back(su);
            
            if(out>=2) break;
        }
        
        if(out>=2) continue;
        sort(all(can));
        
        if(out==0){
            for(int k=0;k<can[1];k++){
                ans*=p;
            }
        }else if(out==1){
            for(int k=0;k<can[0];k++){
                ans*=p;
            }
        }
    }
    
    cout<<ans<<endl;
    
}