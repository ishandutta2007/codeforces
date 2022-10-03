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
const int mod=1000000007,MAX=300005;
const int INF=1<<30;

ll fib[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    fib[0]=fib[1]=1;
    for(int i=2;i<MAX;i++) fib[i]=(fib[i-1]+fib[i-2])%mod;
    for(int i=1;i<MAX;i++) fib[i]=(fib[i]+fib[i-1])%mod;
    
    ll ans=0;
    
    int N,P;cin>>N>>P;
    vector<ll> A(N),use;
    set<ll> SE;
    for(int i=0;i<N;i++){
        cin>>A[i];
        SE.insert(A[i]);
    }
    sort(all(A));
    reverse(all(A));
    
    for(int i=0;i<N;i++){
        ll x=A[i];
        bool f=true;
        while(x){
            if(x&1){
                x/=2;
                if(SE.count(x)){
                    f=false;
                    break;
                }
            }else if(x%4==0){
                x/=4;
                if(SE.count(x)){
                    f=false;
                    break;
                }
            }else{
                break;
            }
        }
        if(f){
            int cn=0;
            x=A[i];
            while(x){
                x/=2;
                cn++;
            }
            if(cn<=P){
                ans+=fib[P-cn];
                ans%=mod;
            }
        }
    }
    
    cout<<ans<<"\n";
}