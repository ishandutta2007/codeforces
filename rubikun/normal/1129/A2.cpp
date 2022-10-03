#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    
    vector<vector<int>> S(N,vector<int>());
    
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        S[a].push_back((N+b-a)%N);
    }
    
    for(int i=0;i<N;i++){
        sort(all(S[i]));
    }
    
    for(int i=0;i<N;i++){
        int ans=0;
        for(int j=0;j<N;j++){
            if(S[(i+j)%N].size()==0) continue;
            ans=max(ans,j+int(S[(i+j)%N].size()-1)*N+S[(i+j)%N][0]);
        }
        
        if(i) cout<<" ";
        cout<<ans;
    }
    cout<<endl;
}