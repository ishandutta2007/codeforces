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
const int mod=1000000007,MAX=100005,INF=1<<29;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<ll> A(N);
        ll sum=0;
        for(int i=0;i<N;i++){
            cin>>A[i];
            sum+=A[i];
        }
        sort(all(A));
        ll ans=0;
        chmax(ans,A.back()*(N-1)-sum);
        if(sum%(N-1)) chmax(ans,ll(N-1)-sum%(N-1));
        cout<<ans<<"\n";
    }
}