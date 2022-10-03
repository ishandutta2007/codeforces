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
        vector<vector<int>> pos(N+1);
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
            pos[A[i]].push_back(i);
        }
        
        vector<pair<int,int>> S;
        for(int i=1;i<=N;i++){
            if(si(pos[i])) S.push_back(mp(si(pos[i]),i));
        }
        sort(all(S));
        reverse(all(S));
        
        vector<int> ans(N);
        
        for(int t=1;;t++){
            if(si(S)==0) break;
            vector<pair<int,int>> X;
            for(auto a:S){
                X.push_back(mp(pos[a.se].back(),a.se));
                pos[a.se].pop_back();
            }
            
            for(int i=0;i<si(X);i++){
                ans[X[i].fi]=X[(i+1)%si(X)].se;
            }
            
            while(si(S)&&S.back().fi==t) S.pop_back();
        }
        
        for(int i=0;i<N;i++) cout<<ans[i]<<" ";
        cout<<"\n";
    }
}