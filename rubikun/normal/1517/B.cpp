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
        int N,M;cin>>N>>M;
        vector<vector<ll>> A(N,vector<ll>(M));
        set<pair<ll,pair<int,int>>> SE;
        vector<set<pair<ll,int>>> B(N);
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>A[i][j];
                SE.insert(mp(A[i][j],mp(i,j)));
                B[i].insert(mp(A[i][j],j));
            }
        }
        
        vector<vector<ll>> ans(N,vector<ll>(M));
        
        for(int q=0;q<M;q++){
            auto it=*SE.begin();
            
            for(int i=0;i<N;i++){
                if(i==it.se.fi){
                    auto it2=mp(it.fi,it.se.se);
                    ans[i][q]=it2.fi;
                    B[i].erase(it2);
                    SE.erase(mp(it2.fi,mp(i,it2.se)));
                }else{
                    auto it2=*B[i].rbegin();
                    ans[i][q]=it2.fi;
                    B[i].erase(it2);
                    SE.erase(mp(it2.fi,mp(i,it2.se)));
                }
            }
        }
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
        
    }
    
}