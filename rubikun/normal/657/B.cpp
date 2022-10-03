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
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;ll K;cin>>N>>K;
    vector<ll> A(N+1),L(N+1),R(N+2),seel(N+1),seer(N+2);
    for(int i=0;i<=N;i++) cin>>A[i];
    L[0]=0;
    seel[0]=1;
    for(int i=0;i<N;i++){
        if(abs(L[i]-A[i])&1){
            break;
        }else{
            L[i+1]=(L[i]-A[i])/2;
            seel[i+1]=1;
        }
    }
    R[N+1]=0;
    seer[N+1]=1;
    for(int i=N;i>=1;i--){
        R[i]=(R[i+1]+A[i])*2;
        seer[i]=1;
        if(abs(R[i])>=(1LL<<50)){
            break;
        }
    }
    
    int ans=0;
    
    for(int i=0;i<=N;i++){
        if(seel[i]&&seer[i+1]){
            if(abs(R[i+1]-L[i])<=K){
                if(i<N) ans++;
                else if(abs(R[i+1]-L[i])) ans++;
            }
        }
    }
    
    cout<<ans<<endl;
}