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
        vector<int> A(N),B(N),C(N),ans(N);
        for(int i=0;i<N;i++) cin>>A[i];
        for(int i=0;i<N;i++) cin>>B[i];
        for(int i=0;i<N;i++) cin>>C[i];
        
        ans[0]=A[0];
        for(int i=1;i<N-1;i++){
            if(ans[i-1]!=A[i]) ans[i]=A[i];
            else if(ans[i-1]!=B[i]) ans[i]=B[i];
            else ans[i]=C[i];
        }
        
        if(ans[0]!=A[N-1]&&ans[N-2]!=A[N-1]) ans[N-1]=A[N-1];
        if(ans[0]!=B[N-1]&&ans[N-2]!=B[N-1]) ans[N-1]=B[N-1];
        if(ans[0]!=C[N-1]&&ans[N-2]!=C[N-1]) ans[N-1]=C[N-1];
        
        for(int a:ans) cout<<a<<" ";
        cout<<"\n";
    }
}