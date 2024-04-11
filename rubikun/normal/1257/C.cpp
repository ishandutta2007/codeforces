#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000003,MAX=300003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int T;cin>>T;
    while(T){
        int N;cin>>N;
        vector<vector<int>> A(N);
        for(int i=0;i<N;i++){
            int a;
            //cin>>a;
            scanf("%d",&a);
            a--;
            A[a].push_back(i);
        }
        
        int ans=INF;
        
        for(int i=0;i<N;i++){
            if(A[i].size()<=1) continue;
            for(int j=1;j<A[i].size();j++){
                ans=min(ans,A[i][j]-A[i][j-1]+1);
            }
        }
        
        if(ans==INF) cout<<-1<<"\n";
        else cout<<ans<<endl;
        
        T--;
    }
    
}