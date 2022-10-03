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
    
    int Q;cin>>Q;
    while(Q--){
        int N,M;cin>>N>>M;
        vector<ll> A(N),B(M),Asum(N),Bsum(M);
        for(int i=0;i<N;i++){
            cin>>A[i];
            A[i]--;
        }
        sort(all(A));
        reverse(all(A));
        for(int i=0;i<M;i++){
            cin>>B[i];
        }
        
        Asum[0]=B[A[0]];
        for(int i=1;i<N;i++) Asum[i]=Asum[i-1]+B[A[i]];
        
        Bsum[0]=B[0];
        for(int i=1;i<M;i++) Bsum[i]=Bsum[i-1]+B[i];
        
        
        ll sum=0,ma=0;
        
        for(int i=0;i<N;i++) sum+=B[A[i]];
        
        for(int i=0;i<min(N,M);i++){
            chmax(ma,Asum[i]-Bsum[i]);
        }
        
        cout<<sum-ma<<"\n";
    }
}