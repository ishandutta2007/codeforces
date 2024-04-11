#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<17,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    if(N%2==1){
        vector<vector<int>> A(N,vector<int>(N));
        
        for(int i=0;i<(N/2)*N;i++){
            A[i/(N/2)][i%(N/2)]=i+1;
        }
        for(int i=(N/2)*N;i<(N/2+1)*N;i++){
            A[i-(N/2)*N][N/2]=i+1;
        }
        for(int i=0;i<N;i++){
            for(int j=N/2+1;j<N;j++){
                A[i][j]=N*N+1-A[i][N-1-j];
            }
        }
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(j) cout<<" ";
                cout<<A[i][j];
            }
            cout<<endl;
        }
    }else{
        vector<vector<int>> A(N,vector<int>(N));
        for(int i=0;i<N;i++){
            for(int j=0;j<N/2;j++){
                A[i][j]=i*(N/2)+j+1;
            }
        }
        for(int i=0;i<N;i++){
            for(int j=N/2;j<N;j++){
                A[i][j]=N*N+1-A[i][N-1-j];
            }
        }
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(j) cout<<" ";
                cout<<A[i][j];
            }
            cout<<endl;
        }
    }
}