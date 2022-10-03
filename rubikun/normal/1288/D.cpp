#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1005,INF=1000000009;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<vector<int>> A(N,vector<int>(M));
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>A[i][j];
        }
    }
    
    int left=0,right=INF;
    int a=1,b=1;
    
    while(right-left>1){
        int mid=(left+right)/2;
        
        vector<int> cnt((1<<M));
        
        for(int i=0;i<N;i++){
            int bit=0;
            for(int j=0;j<M;j++){
                if(A[i][j]>=mid) bit|=(1<<j);
            }
            cnt[bit]=i+1;
        }
        
        bool ok=false;
        
        for(int i=0;i<(1<<M);i++){
            for(int j=0;j<(1<<M);j++){
                if((i|j)==(1<<M)-1&&cnt[i]&&cnt[j]){
                    ok=true;
                    a=cnt[i];
                    b=cnt[j];
                }
            }
        }
        
        if(ok) left=mid;
        else right=mid;
    }
    
    cout<<a<<" "<<b<<endl;
}