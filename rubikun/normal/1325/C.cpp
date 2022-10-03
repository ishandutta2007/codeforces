#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;
vector<pair<int,int>> G[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N-1),B(N-1),ans(N-1,-1);
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        A[i]=a;
        B[i]=b;
        
        G[a].push_back({b,i});
        G[b].push_back({a,i});
    }
    
    for(int i=0;i<N;i++){
        if(G[i].size()>=3){
            for(int j=0;j<G[i].size();j++){
                ans[G[i][j].second]=j;
            }
            int id=G[i].size();
            for(int j=0;j<N-1;j++){
                if(ans[j]==-1){
                    ans[j]=id;
                    id++;
                }
            }
            
            for(int i=0;i<N-1;i++) cout<<ans[i]<<"\n";
            return 0;
        }
    }
    
    for(int i=0;i<N-1;i++) cout<<i<<"\n";
}