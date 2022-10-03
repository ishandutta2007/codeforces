#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        vector<int> A(N+1);
        vector<vector<int>> sum(200,vector<int>(N+1)),wh(200);
        for(int i=0;i<N;i++){
            cin>>A[i+1];
            A[i+1]--;
            sum[A[i+1]][i+1]++;
            wh[A[i+1]].push_back(i+1);
        }
        
        int ans=0;
        
        for(int i=0;i<200;i++){
            for(int j=1;j<=N;j++){
                sum[i][j]+=sum[i][j-1];
            }
            ans=max(ans,sum[i][N]);
        }
        
        for(int i=0;i<200;i++){
            int l=0,r=int(wh[i].size())-1;
            while(l<r){
                int ma=0;
                for(int j=0;j<200;j++){
                    if(i==j) continue;
                    ma=max(ma,sum[j][wh[i][r]-1]-sum[j][wh[i][l]]);
                }
                ans=max(ans,ma+(l+1)*2);
                
                l++;
                r--;
            }
        }
        
        cout<<ans<<"\n";
    }
}