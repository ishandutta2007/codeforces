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

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,L;cin>>N>>L;
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        int ans=0;
        for(int j=0;j<L;j++){
            int a=0;
            for(int i=0;i<N;i++) if(A[i]&(1<<j)) a++;
            if(a>=N-a) ans+=(1<<j);
        }
        cout<<ans<<"\n";
    }
}