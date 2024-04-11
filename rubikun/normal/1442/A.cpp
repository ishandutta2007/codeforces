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
        int N;cin>>N;
        vector<ll> A(N+2),B(N+1);
        for(int i=0;i<N;i++) cin>>A[i+1];
        for(int i=0;i<N+1;i++) B[i]=A[i+1]-A[i];
        
        ll sum1=0,sum2=0;
        
        for(int i=1;i<N;i++){
            if(B[i]<0) sum1+=abs(B[i]);
            else sum2+=B[i];
        }
        
        if(sum1>B[0]){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
}