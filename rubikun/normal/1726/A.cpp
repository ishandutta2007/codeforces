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
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        int ans=A.back()-A.front();
        int mi=INF,ma=-INF;
        for(int i=0;i<N-1;i++) chmin(mi,A[i]);
        for(int i=1;i<N;i++) chmax(ma,A[i]);
        chmax(ans,A.back()-mi);
        chmax(ans,ma-A.front());
        for(int i=0;i<N;i++) A.push_back(A[i]);
        for(int i=0;i<N;i++) chmax(ans,A[i+N-1]-A[i]);
        cout<<ans<<"\n";
    }
}