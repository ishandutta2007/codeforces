#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int t;cin>>t;
  while(t--){
    int n;cin>>n;
    vector<string>A(n),B(n);
    for(int i=0;i<n;i++)cin>>A[i];
    for(int i=0;i<n;i++)cin>>B[i];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)A[i][j]-='0',B[i][j]-='0';
    for(int i=0;i<n-1;i++){
      int a=A[i][0]^A[i+1][0]^B[i][0]^B[i+1][0];
      for(int j=0;j<n;j++){
        if(a!=(A[i][j]^A[i+1][j]^B[i][j]^B[i+1][j])){
          puts("NO");
          goto home;
        }
      }
    }
    for(int i=0;i<n-1;i++){
      int a=A[0][i]^A[0][i+1]^B[0][i]^B[0][i+1];
      for(int j=0;j<n;j++){
        if(a!=(A[j][i]^A[j][i+1]^B[j][i]^B[j][i+1])){
          puts("NO");
          goto home;
        }
      }
    }
    puts("YES");
    home:;
  }
}