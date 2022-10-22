#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int Q;
  cin>>Q;
  while(Q--){
    int N,M;
    cin>>N>>M;
    vector<vector<int>> A(N,vector<int>(M));
    for(int i=0;i<N;i++)
      for(int j=0;j<M;j++){
        cin>>A[i][j];
        A[i][j]+=(i+j+A[i][j])%2;
        cout<<A[i][j]<<(j==M-1?'\n':' ');
      }
  }
}