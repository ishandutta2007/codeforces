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
        int N,M,X;cin>>N>>M>>X;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> PQ;
        
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        
        cout<<"YES\n";
        
        for(int i=0;i<M;i++){
            PQ.push(mp(A[i],i));
            cout<<i+1<<" ";
        }
        
        for(int i=M;i<N;i++){
            auto u=PQ.top();PQ.pop();
            PQ.push(mp(u.fi+A[i],u.se));
            cout<<u.se+1<<" ";
        }
        
        cout<<"\n";
    }
}