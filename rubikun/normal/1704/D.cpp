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
        int N,M;cin>>N>>M;
        //vector<vector<ll>> A(N,vector<ll>(M));
        vector<ll> sum(N);
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                ll x;cin>>x;
                sum[i]+=x*j;
            }
        }
        
        vector<ll> A=sum;
        sort(all(A));
        ll ng=A.back();
        
        for(int i=0;i<N;i++){
            if(sum[i]==ng){
                cout<<i+1<<" "<<(sum[i]-A[0])<<"\n";
            }
        }
    }
}