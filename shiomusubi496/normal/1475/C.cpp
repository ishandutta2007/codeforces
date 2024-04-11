#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int t;cin>>t;
  while(t--){
    int a,b,k,ans;cin>>a>>b>>k;
    ans=k*(k-1)/2;
    vector<int>A(a),B(b);
    for(int i=0;i<k;i++){
      int x;cin>>x;
      ans-=(A[--x]++);
    }
    for(int i=0;i<k;i++){
      int x;cin>>x;
      ans-=(B[--x]++);
    }
    cout<<ans<<endl;
  }
}