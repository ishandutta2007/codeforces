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
const int mod=1000000007,MAX=500005,INF=1<<30;

ll rui(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll N,P;cin>>N>>P;
        vector<ll> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        sort(all(A));
        reverse(all(A));
        
        if(P==1){
            cout<<(N&1)<<"\n";
            continue;
        }
        
        ll ans=0,diff=0;
        
        int i=0;
        
        while(i<N){
            int to=i;
            while(to<N&&A[i]==A[to]) to++;
            
            if(i==0){
                ans=rui(P,A[i])*((to-i)&1);
                diff=(to-i)&1;
                i=to;
            }else{
                while(i<to){
                    if(diff){
                        ans+=mod-rui(P,A[i]);
                        ans%=mod;
                        i++;
                        diff--;
                    }else{
                        ans+=rui(P,A[i]);
                        ans%=mod;
                        i++;
                        diff++;
                    }
                }
            }
            
            if(i<N){
                for(int k=0;k<A[i-1]-A[i];k++){
                    diff*=P;
                    if(diff>1000000000) break;
                    if(diff==0) break;
                }
                if(diff>1000000000){
                    while(i<N){
                        ans+=mod-rui(P,A[i]);
                        ans%=mod;
                        i++;
                    }
                }
            }
        }
        
        cout<<ans<<"\n";
    }
}