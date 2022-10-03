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
const int mod=1000000007,MAX=15;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<ll> A(N),B(N);
        ll a=0,b=0;
        for(int i=0;i<N;i++){
            cin>>A[i];
            a+=A[i];
        }
        for(int i=0;i<N;i++){
            cin>>B[i];
            b+=B[i];
        }
        
        ll now=B[0];
        for(int i=0;i<N-1;i++){
            ll need=max(0LL,A[(i+1)%N]-now);
            now=B[(i+1)%N]-need;
        }
        
        ll want=max(0LL,A[0]-now);
        
        bool ok=true;
        now=B[0]-want;
        if(now<0) ok=false;
        
        for(int i=0;i<N;i++){
            ll need=max(0LL,A[(i+1)%N]-now);
            now=B[(i+1)%N]-need;
            if(now<0) ok=false;
        }
        
        if(ok&&a<=b) cout<<"YES\n";
        else cout<<"NO\n";
    }
}