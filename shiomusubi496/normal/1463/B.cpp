#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int Q;cin>>Q;
  while(Q--){
    int n;cin>>n;
    int a=0,b=0;
    vector<int>A(n),ans(n);
    for(int i=0;i<n;i++){
      cin>>A[i];
      if(i%2==0)a+=A[i];
      else b+=A[i];
    }
    if(a>b){
      for(int i=0;i<n;i++){
        if(i%2==0)ans[i]=A[i];
        else ans[i]=1;
      }
    }else{
      for(int i=0;i<n;i++){
        if(i%2==0)ans[i]=1;
        else ans[i]=A[i];
      }
    }
    for(int i=0;i<n;i++)cout<<ans[i]<<(i==n-1?'\n':' ');
  }
}