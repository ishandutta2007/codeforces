#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200003;
const ll INF=1LL<<61;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int M,N;cin>>M>>N;
    vector<vector<int>> A(M,vector<int>(N));
    for(int i=0;i<M;i++){
        int a;cin>>a;
        for(int j=0;j<a;j++){
            int b;cin>>b;
            b--;
            A[i][b]++;
        }
    }
    
    bool ok=true;
    
    for(int i=0;i<M;i++){
        for(int j=i+1;j<M;j++){
            bool flag=false;
            for(int k=0;k<N;k++){
                if(A[i][k]&&A[j][k]) flag=true;
            }
            if(!flag) ok=false;
        }
    }
    
    if(ok) cout<<"possible"<<endl;
    else cout<<"impossible"<<endl;
    
}