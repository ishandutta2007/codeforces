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
        vector<ll> A(N+2),B(N+1);
        ll sum=0,ans=0;
        for(int i=1;i<=N;i++){
            cin>>A[i];
        }
        
        for(int i=1;i<=N+1;i++){
            B[i-1]=A[i]-A[i-1];
        }
        
        for(int i=1;i<N;i++){
            if(B[i]<0) sum+=-B[i];
            ans+=abs(B[i]);
        }
        
        ans+=abs(B[0]-sum);
        
        cout<<ans<<"\n";
        
    }
}