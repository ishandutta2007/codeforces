#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005,INF=1<<29;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    
    while(Q--){
        int N,K;cin>>N>>K;
        vector<int> A(N),B(2*K+3);
        for(int i=0;i<N;i++) cin>>A[i];
        
        for(int i=0;i<N/2;i++){
            int a=min(A[i],A[N-1-i]),b=max(A[i],A[N-1-i]);
            
            B[2]+=2;
            B[a+1]-=2;
            
            B[a+1]++;
            B[a+b]--;
            
            B[a+b+1]++;
            B[K+b+1]--;
            
            B[K+b+1]+=2;
            B[2*K+1]-=2;
        }
        
        for(int i=1;i<=2*K+2;i++) B[i]+=B[i-1];
        
        int ans=INF;
        
        for(int i=2;i<=2*K;i++) chmin(ans,B[i]);
        
        cout<<ans<<"\n";
    }
}