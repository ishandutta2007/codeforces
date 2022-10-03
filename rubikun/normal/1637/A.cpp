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
        int N;cin>>N;
        vector<int> A(N),ma(N),mi(N);
        for(int i=0;i<N;i++) cin>>A[i];
        ma[0]=A[0];
        for(int i=1;i<N;i++) ma[i]=max(ma[i-1],A[i]);
        mi[N-1]=A[N-1];
        for(int i=N-2;i>=0;i--) mi[i]=min(mi[i+1],A[i]);
        
        bool f=true;
        for(int i=0;i<N-1;i++) f&=(ma[i]<=mi[i+1]);
        
        if(f) cout<<"NO\n";
        else cout<<"YES\n";
    }
}