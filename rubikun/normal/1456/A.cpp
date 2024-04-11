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
        int N,p,k;cin>>N>>p>>k;
        vector<int> need(N);
        string A;cin>>A;
        ll x,y;cin>>x>>y;
        ll ans=1LL<<40;
        
        for(int i=0;i<N;i++) need[i]=1-int(A[i]-'0');
        for(int i=N-1;i>=0;i--){
            if(i+k<N) need[i]+=need[i+k];
        }
        
        for(int i=N-1;i>=0;i--){
            if(N-i>=p){
                chmin(ans,y*i+x*need[i+p-1]);
            }
        }
        
        cout<<ans<<"\n";
    }
}