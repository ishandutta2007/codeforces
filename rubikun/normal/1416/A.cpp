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

//using mint=atcoder::modint998244353;
//using mint=atcoder::modint1000000007;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<vector<int>> A(N+1);
        vector<int> ans(N+1,-1);
        for(int i=0;i<N;i++){
            int a;cin>>a;
            A[a].push_back(i);
        }
        
        for(int i=1;i<=N;i++){
            if(si(A[i])==0) continue;
            
            int x=max(A[i][0]+1,N-A[i].back());;
            
            for(int j=0;j+1<si(A[i]);j++){
                chmax(x,A[i][j+1]-A[i][j]);
            }
            
            while(x<=N){
                if(ans[x]!=-1) break;
                ans[x]=i;
                x++;
            }
        }
        
        for(int i=1;i<=N;i++) cout<<ans[i]<<" ";
        cout<<"\n";
    }
}