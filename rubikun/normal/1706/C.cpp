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
const int mod=998244353,MAX=300005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<ll> H(N);
        for(int i=0;i<N;i++) cin>>H[i];
        if(N&1){
            ll ans=0;
            for(int i=1;i<N-1;i+=2){
                ans+=max(0LL,max(H[i-1],H[i+1])+1-H[i]);
            }
            cout<<ans<<"\n";
        }else{
            vector<ll> L,R;
            for(int i=1;i<N-1;i+=2){
                L.push_back(max(0LL,max(H[i-1],H[i+1])+1-H[i]));
            }
            for(int i=N-2;i>0;i-=2){
                R.push_back(max(0LL,max(H[i-1],H[i+1])+1-H[i]));
            }
            for(int i=1;i<si(L);i++) L[i]+=L[i-1];
            for(int i=1;i<si(R);i++) R[i]+=R[i-1];
            
            ll mi=L.back();
            chmin(mi,R.back());
            
            for(int i=0;i<si(L)-1;i++){
                chmin(mi,L[i]+R[si(R)-2-i]);
            }
            
            cout<<mi<<"\n";
            
        }
    }
}