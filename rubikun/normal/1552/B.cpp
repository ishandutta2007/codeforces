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
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<61;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<vector<int>> A(N,vector<int>(5));
        for(int i=0;i<N;i++){
            for(int j=0;j<5;j++){
                cin>>A[i][j];
            }
        }
        int can=0;
        for(int i=1;i<N;i++){
            int win=0;
            for(int j=0;j<5;j++){
                if(A[can][j]<A[i][j]) win++;
            }
            if(win<=2) can=i;
        }
        
        bool ok=true;
        for(int i=0;i<N;i++){
            if(i==can) continue;
            int win=0;
            for(int j=0;j<5;j++){
                if(A[can][j]<A[i][j]) win++;
            }
            if(win<=2) ok=false;
        }
        if(ok) cout<<can+1<<"\n";
        else cout<<-1<<"\n";
    }
}