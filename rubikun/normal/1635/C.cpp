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
const int INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<ll> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        if(A[N-2]>A[N-1]){
            cout<<-1<<"\n";
            continue;
        }
        if(A[N-1]>=0){
            cout<<N-2<<"\n";
            for(int i=N-3;i>=0;i--) cout<<i+1<<" "<<i+2<<" "<<N<<"\n";
        }else{
            bool f=true;
            for(int i=0;i+1<N;i++) f&=(A[i]<=A[i+1]);
            if(f) cout<<0<<"\n";
            else cout<<-1<<"\n";
        }
    }
}