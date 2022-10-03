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
        ll N,M;cin>>N>>M;
        vector<ll> X;
        vector<ll> A(M);
        for(int i=0;i<M;i++){
            cin>>A[i];A[i]--;
        }
        sort(all(A));
        for(int i=0;i<M;i++){
            ll a=A[(i+1)%M]-A[i]-1;
            if(a<0) a+=N;
            X.push_back(a);
        }
        
        sort(all(X));
        reverse(all(X));
        
        ll ans=N;
        
        ll turn=0;
        for(int t=0;t<si(X);t++){
            ll rem=X[t]-turn*2;
            if(rem<=0){
                continue;
            }else if(rem<=2){
                ans--;
                turn++;
            }else{
                ans-=(rem-1);
                turn+=2;
            }
        }
        
        cout<<ans<<"\n";
    }
}