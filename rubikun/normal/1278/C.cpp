#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<28;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<int> A(2*N);
        int cnt=0;
        for(int i=0;i<2*N;i++){
            cin>>A[i];
            if(A[i]==1) cnt++;
            else cnt--;
        }
        
        vector<int> left(2*N+1,INF),right(2*N+1,INF);
        left[N]=0;
        right[N]=0;
        
        int now=0;
        
        for(int i=N-1;i>=0;i--){
            if(A[i]==1) now++;
            else now--;
            
            left[N+now]=min(left[N+now],N-i);
        }
        
        now=0;
        
        for(int i=N;i<2*N;i++){
            if(A[i]==1) now++;
            else now--;
            
            right[N+now]=min(right[N+now],i-(N-1));
        }
        
        int ans=INF;
        
        for(int i=0;i<2*N+1;i++){
            int j=2*N+cnt-i;
            if(0<=j&&j<2*N+1){
                ans=min(ans,left[i]+right[j]);
            }
        }
        
        cout<<ans<<endl;
    }
}