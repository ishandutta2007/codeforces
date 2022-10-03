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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll N,X;cin>>N>>X;
        vector<ll> A(N);
        ll ma=-INF,mi=INF;
        ll sum=0;
        for(int i=0;i<N;i++){
            ll x;cin>>x;
            chmax(ma,x);
            chmin(mi,x);
            A[i]=x;
            if(i) sum+=abs(A[i]-A[i-1]);
        }
        
        ll M=INF,P=INF;
        for(int i=0;i<N;i++){
            if(i==0){
                chmin(M,A[i]-1);
                chmin(P,X-A[i]);
            }
            if(i==N-1){
                chmin(M,A[i]-1);
                chmin(P,X-A[i]);
            }
            if(i+1<N){
                chmin(M,min(A[i]-1,A[i+1]-1)*2);
                chmin(P,min(X-A[i],X-A[i+1])*2);
            }
        }
        if(mi<=1) M=0;
        if(X<=ma) P=0;
        
        cout<<sum+M+P<<"\n";
    }
}