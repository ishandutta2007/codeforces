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

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    sieve(MAX-2);
    
    int N;cin>>N;
    vector<ll> A(N),B(N);
    for(int i=0;i<N;i++) cin>>A[i]>>B[i];
    
    ll ans=0;
    
    for(int q=0;q<2;q++){
        vector<ll> p;
        for(ll y:prime){
            if(A[0]%y==0){
                p.push_back(y);
                while(A[0]%y==0) A[0]/=y;
            }
        }
        if(A[0]>=2) p.push_back(A[0]);
        for(ll x:p){
            bool ok=true;
            for(int j=1;j<N;j++){
                if(A[j]%x&&B[j]%x) ok=false;
                if(!ok) break;
            }
            if(ok) chmax(ans,x);
        }
        
        swap(A,B);
    }
    
    if(ans<=1) ans=-1;
    
    cout<<ans<<endl;
}