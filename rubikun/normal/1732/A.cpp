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
const int mod=998244353,MAX=300005;
const ll INF=1LL<<60;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        if(N==1){
            if(A[0]==1) cout<<0<<"\n";
            else cout<<1<<"\n";
            continue;
        }
        ll g=0;
        for(int i=0;i<N;i++) g=gcd(g,A[i]);
        
        if(g==1) cout<<0<<"\n";
        else{
            int ans=3;
            vector<int> B=A;
            B[N-2]=gcd(A[N-2],N-1);
            g=0;
            for(int i=0;i<N;i++) g=gcd(g,B[i]);
            
            if(g==1) ans=2;
            
            B=A;
            B[N-1]=gcd(A[N-1],N);
            g=0;
            for(int i=0;i<N;i++) g=gcd(g,B[i]);
            
            if(g==1) ans=1;
            
            cout<<ans<<"\n";
        }
    }
}