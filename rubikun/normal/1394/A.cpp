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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,d,lim;cin>>N>>d>>lim;
    vector<ll> A(N),S(N+1);
    for(int i=0;i<N;i++) cin>>A[i];
    sort(all(A));
    ll M=0;
    
    for(int i=1;i<=N;i++){
        S[i]=A[i-1];
        S[i]+=S[i-1];
        
        if(A[i-1]>lim) M++;
    }
    
    ll ans=0;
    
    for(ll k=0;k<=M;k++){
        ll rem=M-k,sum=S[N];
        if(d*k>=rem){
            if(d*(k-1)>=rem){
                if(d*(k-1)<=N-k){
                    sum-=S[N-k]-S[N-M];
                    sum-=S[d*(k-1)-rem];
                    
                    chmax(ans,sum);
                }
            }else{
                sum-=S[N-k]-S[N-M];
                
                chmax(ans,sum);
            }
        }
    }
    
    cout<<ans<<endl;
}