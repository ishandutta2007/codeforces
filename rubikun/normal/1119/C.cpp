#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=300003,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<vector<int>> A(N,vector<int>(M)),B(N,vector<int>(M));
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>A[i][j];
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>B[i][j];
        }
    }
    
    for(int i=0;i<N-1;i++){
        for(int j=0;j<M-1;j++){
            if(A[i][j]!=B[i][j]){
                A[i][j]^=1;
                A[i][j+1]^=1;
                A[i+1][j]^=1;
                A[i+1][j+1]^=1;
            }
        }
    }
    
    bool ok=true;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(A[i][j]!=B[i][j]) ok=false;
        }
    }
    
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}