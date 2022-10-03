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
        vector<ll> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        if(N<=2){
            cout<<0<<"\n";
            continue;
        }
        int ans=INF;
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                vector<ll> B=A;
                for(int k=0;k<N;k++){
                    B[k]*=(j-i);
                }
                ll d=(B[j]-B[i])/(j-i);
                int need=0;
                for(int k=0;k<N;k++){
                    ll to=B[i]+d*(k-i);
                    if(to!=B[k]) need++;
                }
                chmin(ans,need);
            }
        }
        
        cout<<ans<<"\n";
    }
}