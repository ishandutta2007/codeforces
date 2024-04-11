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
    
    int N,M,H;cin>>N>>M>>H;
    vector<int> A(M),B(N);
    for(int i=0;i<M;i++) cin>>A[i];
    for(int j=0;j<N;j++) cin>>B[j];
    
    vector<vector<int>> C(N,vector<int>(M));
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>C[i][j];
        }
    }
    
    for(int j=0;j<M;j++){
        for(int i=0;i<N;i++){
            if(C[i][j]) C[i][j]=A[j];
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            C[i][j]=min(C[i][j],B[i]);
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
}