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
    
    int T;cin>>T;
    while(T--){
        int N,M,K;cin>>N>>M>>K;
        K=min(K,M-1);
        vector<int> A(N);
        for(int i=0;i<N;i++) cin>>A[i];
        
        
        int maxi=0;
        
        for(int left=0;left<=K;left++){
            int mini=INF;
            
            for(int i=left;i+N-M<N-(K-left);i++){
                mini=min(mini,max(A[i],A[i+N-M]));
            }
            
            maxi=max(maxi,mini);
        }
        
        cout<<maxi<<endl;
    }
}