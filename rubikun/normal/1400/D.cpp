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
const int mod=1000000007,MAX=3005;
const ll INF=1LL<<60;
ll cnt[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        ll N;cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        for(int i=0;i<=N;i++) for(int j=0;j<=N;j++) cnt[i][j]=0;
        ll ans=0;
        
        for(int j=N-1;j>=0;j--){
            for(int i=j-1;i>=0;i--){
                ans+=cnt[A[i]][A[j]];
            }
            for(int k=j+1;k<N;k++){
                cnt[A[j]][A[k]]++;
            }
        }
        
        cout<<ans<<endl;
    }
}