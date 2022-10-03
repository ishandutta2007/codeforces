#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,M;cin>>N>>M;
    vector<vector<int>> A(N,vector<int>(M,0)),B(N,vector<int>(M,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>A[i][j];
        }
    }
    vector<int> ans1,ans2;
    bool ok=true;
    
    for(int i=0;i<N-1;i++){
        for(int j=0;j<M-1;j++){
            if(A[i][j]&&A[i+1][j]&&A[i][j+1]&&A[i+1][j+1]){
                B[i][j]=B[i+1][j]=B[i][j+1]=B[i+1][j+1]=1;
                ans1.push_back(i);
                ans2.push_back(j);
            }
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(A[i][j]!=B[i][j]) ok=false;
        }
    }
    
    if(ok){
        cout<<ans1.size()<<endl;
        for(int i=0;i<ans1.size();i++){
            cout<<ans1[i]+1<<" "<<ans2[i]+1<<endl;
        }
    }else cout<<-1<<endl;
}