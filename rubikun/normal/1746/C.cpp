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
        priority_queue<pair<int,int>> PQ;
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        if(N==1){
            cout<<1<<"\n";
            continue;
        }
        for(int i=1;i<N;i++){
            PQ.push(mp(A[i-1]-A[i],i));
        }
        vector<int> ans(N+1);
        for(int t=N;t>=1;t--){
            auto x=PQ.top();PQ.pop();
            ans[t]=x.se+1;
            PQ.push(mp(x.fi-t,x.se));
        }
        for(int i=1;i<=N;i++) cout<<ans[i]<<" ";
        cout<<"\n";
    }
}