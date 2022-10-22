#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    vector<int>A(2);
    for(int i=0;i<2*n;i++){
      int a; cin>>a;
      A[a%2]++;
    }
    puts(A[0]==A[1]?"Yes":"No");
  }
}