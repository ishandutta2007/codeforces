#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int t;cin>>t;
  while(t--){
    int n,k;cin>>n>>k;
    int m=(n+k-1)/k*k;
    cout<<(m+n-1)/n<<endl;
  }
}