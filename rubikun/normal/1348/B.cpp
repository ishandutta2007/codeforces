#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,M;cin>>N>>M;
        vector<int> A(N);
        set<int> SE;
        for(int i=0;i<N;i++){
            cin>>A[i];
            SE.insert(A[i]);
        }
        
        if(si(SE)>M){
            cout<<-1<<"\n";
        }else{
            cout<<M*100<<"\n";
            for(int i=0;i<100;i++){
                for(int x:SE) cout<<x<<" ";
                for(int j=0;j<M-si(SE);j++) cout<<1<<" ";
            }
            cout<<"\n";
        }
    }
}