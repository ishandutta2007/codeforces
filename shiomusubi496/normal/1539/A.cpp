#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int t; cin>>t;
  while(t--){
    int n,x,t; cin>>n>>x>>t;
    int a=min(t/x,n);
    cout<<a*((n-1)+(n-a))/2<<endl;
  }
}