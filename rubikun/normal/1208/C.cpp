#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<13,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    vector<vector<int>> A(N,vector<int>(N));
    for(int x=0;x<N/4;x++){
        for(int y=0;y<N/4;y++){
            int k=x*(N/4)+y;
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    A[i+x*4][j+y*4]=k*16+i*4+j;
                }
            }
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(j) cout<<" ";
            cout<<A[i][j];
        }
        cout<<"\n";
    }
    
}